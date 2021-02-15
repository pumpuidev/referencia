#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "naplo.h"

using namespace std;

TEST_CASE("intervallum hossza 0", "nincs tantargy")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t20.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==0);
}

TEST_CASE("intervallum hossza 1", "1 tantargy 1 otos")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t11_1.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==1);
}

TEST_CASE("intervallum hossza tobb", "tobb tantargy 1 otos")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_1.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==1);
}

TEST_CASE("intervallum eleje es vege", "elso es az utolso jegy a ket otos")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_2.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==2);
}

TEST_CASE("eredmeny 0", "diaknak nincs otose")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_0.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==0);
}

TEST_CASE("eredmeny 1", "diaknak 1 otose van")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_1.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==1);
}

TEST_CASE("eredmeny 2", "diaknak 2 otose van")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_2.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==2);
}

TEST_CASE("eredmeny 3", "diaknak 2 otose van")
{
    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_3.txt", tanulo, targy, naplo);
    CHECK(otosDb(naplo[0])==3);
}
