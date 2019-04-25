#include "../src/geometry.h"
#include "../thirdparty/ctest.h"

CTEST(geometry, S_Circle_Circle_r2)
{
    // Given
    Figure a = {CIRCLE, {0, 0, 2}, 3};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = M_PI * 4;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, S_Circle_Circle_r0)
{
    // Given
    Figure a = {CIRCLE, {0}, 3};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, S_Circle_Circle_coords_0)
{
    // Given
    Figure a = {CIRCLE, {0}, 0};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}
CTEST(geometry, S_Circle_Circle_coords_0_r5)
{
    // Given
    Figure a = {CIRCLE, {0, 0, 5}, 0};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, S_Circle_Circle_coords_1)
{
    // Given
    Figure a = {CIRCLE, {0}, 1};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}
CTEST(geometry, S_Circle_Circle_coords_4)
{
    // Given
    Figure a = {CIRCLE, {0}, 4};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, S_Circle_Circle_r_not1)
{
    // Given
    Figure a = {CIRCLE, {0, 0, -1}, 3};
    // When
    double result_a = 0.0;
    S_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}
CTEST(geometry, S_Circle_Triangle)
{
    // Given
    Figure b = {TRIANGLE, {0, 0, 2, 2, 0, 3, 0, 0}, 8};

    // When
    double result_b = 0.0;
    S_Circle(&result_b, &b);

    // Then
    const double expected_b = 0;

    ASSERT_DBL_NEAR(expected_b, result_b);
}

CTEST(geometry, S_Circle_NULL)
{
    // Given
    double result_c = 0.0;
    S_Circle(&result_c, NULL);

    // Then
    const double expected_c = 0;

    ASSERT_DBL_NEAR(expected_c, result_c);
}
/*----------------------------------------------------------------------------*/

CTEST(geometry, P_Circle_Circle_r2)
{
    // Given
    Figure a = {CIRCLE, {0, 0, 2}, 3};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = M_PI * 4;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Circle_r0)
{
    // Given
    Figure a = {CIRCLE, {0}, 3};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Circle_coords_0)
{
    // Given
    Figure a = {CIRCLE, {0}, 0};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Circle_coords_0_r5)
{
    // Given
    Figure a = {CIRCLE, {0, 0, 5}, 0};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Circle_coords_1)
{
    // Given
    Figure a = {CIRCLE, {0}, 1};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}
CTEST(geometry, P_Circle_Circle_coords_4)
{
    // Given
    Figure a = {CIRCLE, {0}, 4};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Circle_r_not1)
{
    // Given
    Figure a = {CIRCLE, {0, 0, -1}, 3};
    // When
    double result_a = 0.0;
    P_Circle(&result_a, &a);

    // Then
    const double expected_a = 0;

    ASSERT_DBL_NEAR(expected_a, result_a);
}

CTEST(geometry, P_Circle_Triangle)
{
    // Given
    Figure b = {TRIANGLE, {0, 0, 2, 2, 0, 3, 0, 0}, 8};

    // When
    double result_b = 0.0;
    P_Circle(&result_b, &b);

    // Then
    const double expected_b = 0;

    ASSERT_DBL_NEAR(expected_b, result_b);
}

CTEST(geometry, P_Circle_NULL)
{
    // Given
    double result_c = 0.0;
    P_Circle(&result_c, NULL);

    // Then
    const double expected_c = 0;

    ASSERT_DBL_NEAR(expected_c, result_c);
}
/*----------------------------------------------------------------------------*/
CTEST(geometry, P_triangle_triangle)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = a + b + c;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, P_Triangle_Circle)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {CIRCLE, {2, -3, 2}, 3};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, P_triangle_triangle_coord_0)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 0};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, P_triangle_triangle_coord_10)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 10};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = a + b + c;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, P_triangle_triangle_all_coordinates_0)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, P_triangle_triangle_345)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 12.0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}
/*
CTEST(geometry, P_triangle_triangle_NULL)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(NULL, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}
*/
CTEST(geometry, P_triangle_triangle_one_line)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 3, 3, 4, 4, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    P_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = a + b + c;

    ASSERT_DBL_NEAR(expected_d, result_d);
}
/*----------------------------------------------------------------------------*/

CTEST(geometry, S_triangle_triangle)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 6.0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, S_Triangle_Circle)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {CIRCLE, {2, -3, 2}, 3};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, S_triangle_triangle_coord_0)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 0};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, S_triangle_triangle_coord_10)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 10};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 4.0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, S_triangle_triangle_all_coordinates_0)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

CTEST(geometry, S_triangle_triangle_345)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 6.0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}
/*
CTEST(geometry, S_triangle_triangle_NULL)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {-3, -2, -1, 0, -3, 2, -3, -2}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(NULL, a, b, c);

    // Then
    const double expected_d = 0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}
*/
CTEST(geometry, S_triangle_triangle_one_line)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 3, 3, 4, 4, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double result_d = 0.0;
    S_Triangle(&result_d, a, b, c);

    // Then
    const double expected_d = 0.0;

    ASSERT_DBL_NEAR(expected_d, result_d);
}

/*----------------------------------------------------------------------------*/

CTEST(geometry, Vector)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, &b, &c);
    // When
    double expected_a = 3;
    double expected_b = 5;
    double expected_c = 4;
    // Then
    ASSERT_DBL_NEAR(expected_a, a);
    ASSERT_DBL_NEAR(expected_b, b);
    ASSERT_DBL_NEAR(expected_c, c);
}

CTEST(geometry, Vector_NULL1)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(NULL, &a, &b, &c);
    // When
    double expected_a = 0;
    double expected_b = 0;
    double expected_c = 0;
    // Then
    ASSERT_DBL_NEAR(expected_a, a);
    ASSERT_DBL_NEAR(expected_b, b);
    ASSERT_DBL_NEAR(expected_c, c);
}

CTEST(geometry, Vector_NULL2)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, NULL, &b, &c);
    // When
    double expected_a = 0;
    double expected_b = 0;
    double expected_c = 0;
    // Then
    //    ASSERT_DBL_NEAR(expected_a, a);
    ASSERT_DBL_NEAR(expected_b, b);
    ASSERT_DBL_NEAR(expected_c, c);
}

CTEST(geometry, Vector_NULL3)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, NULL, &c);
    // When
    double expected_a = 0;
    double expected_b = 0;
    double expected_c = 0;
    // Then
    ASSERT_DBL_NEAR(expected_a, a);
    //    ASSERT_DBL_NEAR(expected_b, b);
    ASSERT_DBL_NEAR(expected_c, c);
}

CTEST(geometry, Vector_NULL4)
{
    // Given
    double a;
    double b;
    double c;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(&d, &a, &b, NULL);
    // When
    double expected_a = 0;
    double expected_b = 0;
    double expected_c = 0;
    // Then
    ASSERT_DBL_NEAR(expected_a, a);
    ASSERT_DBL_NEAR(expected_b, b);
    //    ASSERT_DBL_NEAR(expected_c, c);
}

CTEST(geometry, Vector_NULL5)
{
    // Given
    double a = -1;
    double b = -1;
    double c = -1;
    Figure d = {TRIANGLE, {0, 0, 0, 3, 4, 0, 0, 0}, 8};
    Vector(NULL, NULL, NULL, NULL);
    // When
    double expected_a = -1;
    double expected_b = -1;
    double expected_c = -1;

    ASSERT_DBL_NEAR(expected_a, a);
    ASSERT_DBL_NEAR(expected_b, b);
    ASSERT_DBL_NEAR(expected_c, c);
    // Then
}
/*----------------------------------------------------------------------------*/
