#include "common.h"

TEST(io, iostuff) {
    FILE * f = std::fopen(TF, "w");
    IOStuff<double, string, int> tup(std::make_tuple(1.0, "xxxx", 2));
    forwritefree(f, tup);
    fflush(f);
    fclose(f);
    double d; string s; int i;
    IOStuff<double*, string*, int*> tupr(std::make_tuple(&d, &s, &i));
    f = std::fopen(TF, "r");
    forreadfree(f, tupr);
    ASSERT_EQ(d, 1.0);
    ASSERT_EQ(s, "xxxx");
    ASSERT_EQ(i, 2);
    fclose(f);
}

TEST(io, implieddo){
    auto g = make_implieddo({ 1, 1 }, { 3, 3 }, [](fsize_t * i) {
        return i[0] + i[1];
    });
    int ans1[] = {2,3,4,3,4,5,4,5,6};
    int * ansp = ans1;
    while(1){
        int x;
        bool hasnext = g.get_next(x);
        ASSERT_EQ(*ansp, x);
        ansp++;
        if(!hasnext) break;
    }
    
    FILE * f = std::fopen(TF, "w");
    forwrite(f, "%d", make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current) {
        return [&](fsize_t j) {
            return make_iostuff(make_tuple(j + 1, j + 2));
        }(current[0]);
    }));
    fflush(f);
    fclose(f);
    ASSERT_EQ(RF(), "2\n3\n3\n4\n");
}

TEST(io, implieddo2){
    farray<int> a{ { 1 },{ 2 } };
    farray<int> b{ { 1, 1 },{ 2, 2 } };

    a(1) = 1;
    a(2) = 2;
    b(1, 1) = 4; b(1, 2) = 5;
    b(2, 1) = 6; b(2, 2) = 7;
    // generated 1d write
    FILE * f = std::fopen(TF, "w");
    forwrite(f, "%d %d%s", make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i) {
            return make_iostuff(make_tuple(make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_j) {
                return [&](fsize_t j) {
                    return b(FW(j), FW(j));
                }(current_j[0]);
            }), ";"));
        }(current_i[0]);
    }));
    
    // generated 2d write
    forwrite(f, "%d %d %d%s", make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i) {
            return make_iostuff(make_tuple(a(FW(i)), make_implieddo({ i, 1 }, { i, 2 }, [&](const fsize_t * current_j) {
                return [&](fsize_t i, fsize_t j) {
                    return b(FW(i), FW(j));
                }(current_j[0], current_j[1]);
            }), ";"));
        }(current_i[0]);
    }));
    fclose(f);
    ASSERT_EQ(RF(), "4 7;\n4 7;\n1 4 5;\n2 6 7;\n");

    // read 
    f = std::fopen(TF, "w");
    fprintf(f, "1 2 3 4\n");
    fprintf(f, "1 2 3 4 5 6\n");
    fclose(f);
    std::fopen(TF, "r");
    auto zz = make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i) {
            return make_iostuff(make_tuple(make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_j) {
                    return [&](fsize_t j) {
                        return &b(FW(j), FW(j));
                    }(current_j[0]);
                })
            ));
        }(current_i[0]);
    });
    forreadfree(f, zz);
    ASSERT_EQ(b(1, 1), 3);
    ASSERT_EQ(b(2, 2), 4);

    // generated 2d read
    forreadfree(f, make_implieddo({ 1 }, { 2 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i) {
            return make_iostuff(make_tuple(&a(FW(i)), make_implieddo({ i, 1 }, { i, 2 }, [&](const fsize_t * current_j) {
                return [&](fsize_t i, fsize_t j) {
                    return &b(FW(i), FW(j));
                }(current_j[0], current_j[1]);
            })));
        }(current_i[0]);
    }));
    ASSERT_EQ(a(1), 1);
    ASSERT_EQ(b(1, 1), 2);
    ASSERT_EQ(b(1, 2), 3);
    ASSERT_EQ(a(2), 4);
    ASSERT_EQ(b(2, 1), 5);
    ASSERT_EQ(b(2, 2), 6);
    fclose(f);
    
    // test _map_impl_next
    f = std::fopen(TF, "w");
    forwritefree(f, make_implieddo({ 1 }, { 10 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i) {
            return i;
        }(current_i[0]);
    }));
    forwritefree(f, make_implieddo({ 1, 1 }, { 1, 2 }, [&](const fsize_t * current_i) {
        return [&](fsize_t i, fsize_t j) {
            return make_iostuff(make_tuple(i, j));
        }(current_i[0], current_i[1]);
    }));
    fclose(f);
    ASSERT_EQ(RF(), "1 2 3 4 5 6 7 8 9 10\n1 1 1 2\n");
}


TEST(io, rewindbackspace){
    FILE * f = fopen(TF, "w");
    fprintf(f, "1\n2\n3\n");
    fclose(f);

    foropenfile(1, None, None, SS(TF), SS("unknown"), SS("sequential"), None, None, None, SS("rewind"), SS("readwrite"), None, None);
    int x;
    forreadfree(get_file(1), &x);
    ASSERT_EQ(x, 1);
    forreadfree(get_file(1), &x);
    ASSERT_EQ(x, 2);
    forrewind(get_file(1), None, None);
    forreadfree(get_file(1), &x);
    ASSERT_EQ(x, 1);

    forbackspace(get_file(1), None, None);
    forreadfree(get_file(1), &x);
    ASSERT_EQ(x, 1);
}

TEST(io, format) {
    FILE * f = fopen(TF, "w");
    fprintf(f, "123456789");
    fclose(f);
    string rr = "";
    f = fopen(TF, "r");
    auto fmt = IOFormat{ "%5s", 0 };
    forread(f, fmt, &rr);
    ASSERT_EQ(rr, "12345");
}


int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    auto r = RUN_ALL_TESTS();
    return r;
}