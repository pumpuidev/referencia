#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "naplo.h"

using namespace std;

TEST_CASE("intervallum hossza 0", "0×m matrix")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t00.txt", tanulo, targy, naplo);
    CHECK(mindenkinek_ket_otos(naplo));

    fajlbol_olvas("t03.txt", tanulo, targy, naplo);
    CHECK(mindenkinek_ket_otos(naplo));
}

TEST_CASE("intervallum hossza 1", "1×m matrix")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t11_1.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));
}

TEST_CASE("intervallum hossza tobb", "n×m matrix")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t33_213.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));
}

TEST_CASE("intervallum eleje", "elso diaknak nincs otose")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t32_122.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));
}

TEST_CASE("intervallum vege", "utolso diaknak nincs otose")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t32_221.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));
}

TEST_CASE("eredmeny pozitiv", "mindkét diaknak ket otose van")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t23_23.txt", tanulo, targy, naplo);
    CHECK(mindenkinek_ket_otos(naplo));

    fajlbol_olvas("t32_222.txt", tanulo, targy, naplo);
    CHECK(mindenkinek_ket_otos(naplo));
}

TEST_CASE("eredmeny negativ", "elso illetve utolso diaknak nincs két otose")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t32_122.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));

    fajlbol_olvas("t32_110.txt", tanulo, targy, naplo);
    CHECK_FALSE(mindenkinek_ket_otos(naplo));
}
