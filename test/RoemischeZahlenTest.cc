#include "gtest/gtest.h"

extern "C" {
    #include "roemisch.h"
}

TEST(RoemischeZahlen, erzeugtEinfacheLiterale) {
    ASSERT_STREQ("I", roemischFuer(1));
    ASSERT_STREQ("MDCLXVI", roemischFuer(1666));
}
TEST(RoemischeZahlen, erzeugtAdditiveKombinationen) {
    ASSERT_STREQ("II", roemischFuer(2));
    ASSERT_STREQ("VII", roemischFuer(7));
}
TEST(RoemischeZahlen, erzeugtSubtraktiveKombinationen) {
    ASSERT_STREQ("CDXLIV", roemischFuer(444));
    ASSERT_STREQ("CMXCIX", roemischFuer(999));
}
