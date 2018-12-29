#include "common.h"

TEST(farray, hiddendo){
    farray<int> e = make_init_list({ 1,1 }, { 2,2 }, [](const fsize_t * current) {return ([](fsize_t i, fsize_t j) {return i + j; })(current[0], current[1]); });
    FILE * f = std::fopen(TF, "w");
    forwritefree(f, e); // 2 3 3 4
    forwrite(f, "%d %d\n", e); // 2 3\n 3 4
    fclose(f);
    ASSERT_EQ(RF(), "2 3 3 4\n2 3\n3 4\n");
}

TEST(farray, constructor_combine){
    // https://ideone.com/CipEpa
    farray<int> a({ 1 }, { 6 }, { 1, 2, 3, 4, 5, 6 });
    farray<int> b({ 1 }, { 6 }, { 1, 2, 3, 4, 5, 6 });
    farray<int> c = make_init_list({1}, {3}, [](const fsize_t * current){return [](fsize_t i){return to_int(i) + 1;}(current[0]);});
    forprintfree(farray<int>({1}, {3}, forslice(a, {{2, 4}})));
    forprintfree(farray<int>({1}, {3}, {b(1), b(2), b(3)}));
    forprintfree(c);
    farray<int> d({1, 1}, {3, 3}, forconcat({ farray<int>({1}, {3}, forslice(a, {{2, 4}})), 
                                        farray<int>({1}, {3}, {b(1), b(2), b(3)}), 
                                        c
                                     }));
    FILE * f = std::fopen(TF, "w");
    forwritefree(f, d);
    fclose(f);
    ASSERT_EQ(RF(), "2 3 4 1 2 3 2 3 4\n");
}

TEST(farray, formerge){
    FILE * f = std::fopen(TF, "w");
    farray<int> a({ 1, 1 }, { 2, 3 }, { 1, 2, 3, 4, 5, 6 });
    farray<int> a1({ 1, 1 }, { 2, 3 }, { 8, 9, 0, 1, 2, 3 });
    farray<bool> logi({ 1, 1 }, { 2, 3 }, {false, true, true, true, true, false });
    forwritefree(f, formerge(a, a1, logi));
    fclose(f);
    ASSERT_EQ(RF(), "8 2 3 4 5 3\n");
}

TEST(farray, map){
    FILE * f = std::fopen(TF, "w");
    farray<int> a = forconcat({ make_init_list({1,2,3}) });
    a.map([&](int & x, fsize_t * cur) {
        x = x + 1;
    });
    forwritefree(f, a);
    fflush(f);
    fclose(f);
    ASSERT_EQ(RF(), "2 3 4\n");
}

TEST(farray, transpose){
    farray<int> a({ 1,1,1 }, { 2,2,2 });
    farray<int> b({ 1,1,1 }, { 2,2,2 });
    a = forreshape({ 1, 2, 3, 4, 5, 6, 7, 8 }, { 2, 2, 2 });
    b = forreshape({ 1, 2, 3, 4, 5, 6, 7, 8 }, { 2, 2, 2 });
    b.transpose();
    //forprintfree(a(2, 2, 1) , "  ", b(1 ,2 ,2));
    farray<int> c({ 1,1 }, { 2,3 });
    farray<int> d({ 1,1 }, { 2,3 });
    c = forreshape({ 1, 2, 3, 4, 5, 6 }, { 2, 3 });
    d = forreshape({ 1, 2, 3, 4, 5, 6 }, { 2, 3 });
    d.transpose();
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            ASSERT_EQ(c(i, j), d(j, i));
        }
    }
    return 0;
}

TEST(farray, maxloc){
// result in http://www.lahey.com/docs/lfprohelp/F95ARMAXLOCFn.htm
    farray<int> a( { 1, 1 },{ 2, 3 }, { -14,3,0,-2,19,1 } );
    ASSERT_EQ(formaxloc(a, 1), make_init_list({2, 1, 1}));
    ASSERT_EQ(formaxloc(a, 2), make_init_list({3, 1}));
    ASSERT_EQ(formaxval(a, 1), make_init_list({3, 0, 19}));
    ASSERT_EQ(formaxval(a, 2), make_init_list({19, 3}));
    ASSERT_EQ(formaxval(a), 19);
    ASSERT_EQ(formaxval(a, 1, a > 1), make_init_list({3, -2147483647, 19}));
}

TEST(farray, operators){
    farray<int> a{ { 1, 1 },{ 2, 3 },{ -14,3,0,-2,19,1 } };
    ASSERT_EQ(a < 3, farray<bool>({ 1, 1 },{ 2, 3 }, {true, false, true, true, false, true}));
    ASSERT_EQ(a > 1, farray<bool>({ 1, 1 },{ 2, 3 }, {false, true, false, false, true, false}));
    ASSERT_EQ(a == 3, farray<bool>({ 1, 1 },{ 2, 3 }, {false, true, false, false, false, false}));
    ASSERT_EQ(a != 1, farray<bool>({ 1, 1 },{ 2, 3 }, {true, true, true, true, true, false}));
    ASSERT_EQ(a + 1, farray<int>({ 1, 1 },{ 2, 3 }, {-13, 4, 1, -1, 20, 2}));
    ASSERT_EQ(a - 2, farray<int>({ 1, 1 },{ 2, 3 }, {-16, 1, -2, -4, 17, -1}));
    ASSERT_EQ(a * 2, farray<int>({ 1, 1 },{ 2, 3 }, {-28, 6, 0, -4, 38, 2}));
    ASSERT_EQ(a / 5, farray<int>({ 1, 1 },{ 2, 3 }, {-2, 0, 0, 0, 3, 0}));
    ASSERT_EQ(!a, farray<bool>({ 1, 1 },{ 2, 3 }, {false, false, true, false, false, false}));
    ASSERT_EQ(!!a, farray<bool>({ 1, 1 },{ 2, 3 }, {true, true, false, true, true, true}));
    return 0;
}

TEST(farray, slice){
    farray<int> b{ { 1, 1 },{ 2, 2 },{ 1,2,3,4 } };
    ASSERT_EQ(forslice(b, { { /* ALL */ }, { 1 /* ELEMENT */} }), farray<int>({1}, {2}, {1, 2}));
    ASSERT_EQ(forslice(b, { { }, { 2,2 /* SLICE */} }), farray<int>({1, 1}, {1, 2}, {3, 4}));
    ASSERT_EQ(forslice(b, { { 1,1 },{  } }), farray<int>({1, 1}, {1, 2}, {1, 3}));
    ASSERT_EQ(forslice(b, { { 2 },{} }), farray<int>({1}, {2}, {2, 4}));
    farray<int> aa = forconcat({ make_init_list({1,2,3}) });
    farray<int> c{ { 1 },{ 3 } };
    c = forslice(aa, { {} });
    forprintfree(c);
}

TEST(farray, io){
    FILE * f = std::fopen(TF, "w");
    farray<int> aa = forconcat({ make_init_list({1,2,3,4,5,6}) });
    forwrite(f, "%d %d %d", aa);
    fclose(f);
    ASSERT_EQ(RF(), "1 2 3\n4 5 6\n");
}

TEST(farray, implieddo){
    FILE * f = std::fopen(TF, "w");
    forwrite(f, "%d %d %d", make_implieddo({ 2 }, { 4 }, [](fsize_t * current) {
        return [](int i) {
            return i + 1;
        }(current[0]);
    }));
    fclose(f);
    ASSERT_EQ(RF(), "3 4 5\n");
}

TEST(farray, order){
    // https://ideone.com/7PRbgE
    farray<int> a({ 1, 1 }, { 2, 4 });
    a = make_init_list({ 1,2,3,4,5,6,7,8 });
    ASSERT_EQ(a(1,2), 3);
    ASSERT_EQ(a(2,1), 2);
    ASSERT_EQ(a(2,3), 6);
    ASSERT_EQ(a(2,2), 4);
    ASSERT_EQ(a(1,4), 7);
}

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    auto r = RUN_ALL_TESTS();
    return r;
}