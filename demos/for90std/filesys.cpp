#include "common.h"

TEST(filesys, rw) {
    foropenfile(1, None, None, SS(TF), SS("replace"), None, None, None, None, None, SS("write"), None, None);
    int a = 22222;
    forwrite(get_file(1), "%d", a);
    a = 33333;
    forclosefile(1, None);

    foropenfile(2, None, None, SS(TF), SS("old"), None, None, None, None, None, SS("read"), None, None);
    forreadfree(get_file(2), &a);
    ASSERT_EQ(a, 22222);
}

TEST(filesys, repeatrw){
    foropenfile(1, None, None, SS(TF), SS("replace"), None, None, None, None, None, SS("write"), None, None);
    int a = 11111, b = 22222;
    forwrite(get_file(1), "%d %d", a);
    a = 0;
    forclosefile(1, None);

    foropenfile(2, None, None, SS(TF), SS("old"), None, None, None, None, None, SS("read"), None, None);
    forreadfree(get_file(2), &a);
    ASSERT_EQ(a, 11111);

    // foropenfile(3, None, None, SS(TF), SS("old"), None, None, None, None, None, SS("read"), None, None);
    // forreadfree(get_file(3), &a);
    // ASSERT_EQ(a, 22222);
}

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    auto r = RUN_ALL_TESTS();
    return r;
}