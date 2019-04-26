#include "../src/parser.h"
#include "../thirdparty/ctest.h"

CTEST(geometry, First_Character_normal)
{
    // Given
    char* a = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 0;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_normal_2)
{
    // Given
    char* a = "circle(0 0, 1.5)";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 0;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_1)
{
    // Given
    char* a = "Zircle(0 0, 1.5)";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_2)
{
    // Given
    char* a = "1riangle((3 -2, 3 2, 1 0, 3 -2))";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_3)
{
    // Given
    char* a = "Zircle(0 0, 1..5)";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_5)
{
    // Given
    char* a = "circle((0 0, 1.5)";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_6)
{
    // Given
    char* a = "triangle(3 -2, 3 2, 1 0, 3 -2))";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_7)
{
    // Given
    char* a = "circle(0,,,,,,,, 0, 1.5)";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(geometry, First_Character_Error_8)
{
    // Given
    char* a = "triangle((3 -svsdg2, 3 2, 1 0, 3 -2))";
    // When
    int real = First_Character(a);
    // Then
    const int exp = 1;
    ASSERT_EQUAL(exp, real);
}
/*----------------------------------------------------------------------------*/
