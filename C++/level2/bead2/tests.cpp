#include "catch.hpp"
#include "enor.h"

using namespace std;

//#define CHECK_ENOR

namespace TestCases
{
    #ifdef CHECK_ENOR

    TEST_CASE("Felsorolo tesztje")
    {
        ifstream ifs;

        SECTION("Nemletezo file")
        {
            Enor t("f10.txt");
            t.First();
            CHECK(t.End());
        }

        SECTION("Ures file")
        {
            Enor t("f0.txt");
            t.First();
            CHECK(t.End());
        }

        SECTION("Egy orszag, nulla varos")
        {
            Enor t("f1.txt");
            t.First();
            CHECK(!t.End());
            CHECK("Romania" == t.Current().orszag);
            CHECK(t.Current().varosok.empty());
            t.Next();
            CHECK(t.End());
        }

        SECTION("Egy orszag, egy varos")
        {
            Enor t("f6.txt");
            t.First();
            CHECK(!t.End());
            CHECK("Romania" == t.Current().orszag);
            CHECK(1 == t.Current().varosok.size());
            CHECK("Kolozsvar" == t.Current().varosok[0].nev);
            CHECK(320 == t.Current().varosok[0].lakok);
            t.Next();
            CHECK(t.End());
        }

        SECTION("Egy orszag, tobb varos")
        {
            Enor t("f7.txt");
            t.First();
            CHECK(!t.End());
            CHECK("Romania" == t.Current().orszag);
            CHECK(3 == t.Current().varosok.size());
            CHECK("Kolozsvar" == t.Current().varosok[0].nev);
            CHECK("Temesvar" == t.Current().varosok[1].nev);
            CHECK("Arad" == t.Current().varosok[2].nev);
            CHECK(320 == t.Current().varosok[0].lakok);
            CHECK(320 == t.Current().varosok[1].lakok);
            CHECK(160 == t.Current().varosok[2].lakok);
            t.Next();
            CHECK(t.End());
        }

        SECTION("Tobb orszag, tobb varos, van ures orszag is, van tobbszavas varos is")
        {
            Enor t("f8.txt");
            t.First();
            CHECK(!t.End());
            CHECK("Mexiko" == t.Current().orszag);
            CHECK(4 == t.Current().varosok.size());
            CHECK("Ciudad de Mexico" == t.Current().varosok[0].nev);
            CHECK("Guadalajara" == t.Current().varosok[1].nev);
            CHECK("Monterrey" == t.Current().varosok[2].nev);
            CHECK("Tijuana" == t.Current().varosok[3].nev);
            CHECK(8800 == t.Current().varosok[0].lakok);
            CHECK(1450 == t.Current().varosok[1].lakok);
            CHECK(1300 == t.Current().varosok[2].lakok);
            CHECK(1300 == t.Current().varosok[3].lakok);
            t.Next();
            CHECK(!t.End());
            CHECK("Japan" == t.Current().orszag);
            CHECK(3 == t.Current().varosok.size());
            CHECK("Szapporo" == t.Current().varosok[0].nev);
            CHECK("Fukuoka" == t.Current().varosok[1].nev);
            CHECK("Oszaka" == t.Current().varosok[2].nev);
            CHECK(1900 == t.Current().varosok[0].lakok);
            CHECK(1400 == t.Current().varosok[1].lakok);
            CHECK(2600 == t.Current().varosok[2].lakok);
            t.Next();
            CHECK(!t.End());
            CHECK("USA" == t.Current().orszag);
            CHECK(2 == t.Current().varosok.size());
            CHECK("New York" == t.Current().varosok[0].nev);
            CHECK("Seattle" == t.Current().varosok[1].nev);
            CHECK(8300 == t.Current().varosok[0].lakok);
            CHECK(600 == t.Current().varosok[1].lakok);
            t.Next();
            CHECK(!t.End());
            CHECK("Romania" == t.Current().orszag);
            CHECK(t.Current().varosok.empty());
            t.Next();
            CHECK(t.End());
        }
    }

    #endif // CHECK_ENOR

}
