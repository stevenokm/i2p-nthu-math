#include "lecture18_ex.h"
#include "gtest/gtest.h"

namespace
{

    TEST(Vector_3D, Init)
    {
        Vector_3D v1(1, 2, 3);

        EXPECT_EQ(1, v1.get_x());
        EXPECT_EQ(2, v1.get_y());
        EXPECT_EQ(3, v1.get_z());
    }

    TEST(Vector_3D, WriteFile)
    {
        Vector_3D v1(1, 2, 3);
        Vector_3D v2(4, 5, 6);

        ofstream ofs("vector_writetest.bin", ios::binary | ios::trunc);
        v1.write_binary(ofs);
        v2.write_binary(ofs);
        ofs.close();

        ifstream ifs("vector_writetest.bin", ios::binary);

        // test v1
        double x, y, z;
        ifs.read((char *)&x, sizeof(double));
        ifs.read((char *)&y, sizeof(double));
        ifs.read((char *)&z, sizeof(double));
        EXPECT_EQ(x, v1.get_x());
        EXPECT_EQ(y, v1.get_y());
        EXPECT_EQ(z, v1.get_z());

        // test v2
        ifs.read((char *)&x, sizeof(double));
        ifs.read((char *)&y, sizeof(double));
        ifs.read((char *)&z, sizeof(double));
        EXPECT_EQ(x, v2.get_x());
        EXPECT_EQ(y, v2.get_y());
        EXPECT_EQ(z, v2.get_z());

        ifs.close();
    }

    TEST(Vector_3D, ReadFile)
    {
        Vector_3D v1(1, 2, 3);
        Vector_3D v2(4, 5, 6);

        ofstream ofs("vector_readtest.bin", ios::binary | ios::trunc);
        v1.write_binary(ofs);
        v2.write_binary(ofs);
        ofs.close();

        ifstream ifs("vector_readtest.bin", ios::binary);

        // test v1
        Vector_3D v3;
        v3.read_binary(ifs);
        EXPECT_EQ(v1.get_x(), v3.get_x());
        EXPECT_EQ(v1.get_y(), v3.get_y());
        EXPECT_EQ(v1.get_z(), v3.get_z());

        // test v2
        v3.read_binary(ifs);
        EXPECT_EQ(v2.get_x(), v3.get_x());
        EXPECT_EQ(v2.get_y(), v3.get_y());
        EXPECT_EQ(v2.get_z(), v3.get_z());

        ifs.close();
    }

} // namespace