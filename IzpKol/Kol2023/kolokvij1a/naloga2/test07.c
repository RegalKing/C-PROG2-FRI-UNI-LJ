
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

char* NIZI[] = {
    "ZgKezu_BuBZD",
    "MOZbsDfuPKjF",
    "qXQzvx6WtbSR",
    "RPz4fjXye7xj",
    "cuZ5T4LDTR9e",
    "XB7sEAy0t37O",
    "EpYtKKNJN4SQ",
    "5pZLgjUu4ZHV",
    "bsmJ_GuhvQ0K",
    "Tbf2Ml7g0wi0",
    "JRv2kObzCXPd",
    "JHiKjauOAfYM",
    "0sIbOdhX91Km",
    "6C96ZH5lQLvQ",
    "6u8ynRJKEZzn",
    "u7mBuHkxcST8",
    "UEA835hOhcDT",
    "WFmOe8YCjG0x",
    "wS2wglxxDlPv",
    "k_VsOggqkn6q",
    "bkbBsdSANxcS",
    "V6EC7c0o56b4",
    "0yudEWwPHk3t",
    "F_U8ryZdgKw8",
    "Axb5vDxXXG8P",
    "14s_VnNC9clJ",
    "emPXdEC4vV66",
    "BFZyFjF_iOUb",
    "nJJ8IzuqrDhS",
    "UOs3f1x_EDBg",
    "kgGXPTjCoed4",
    "TuY95HKGwR4u",
    "OcVTmiL8S_n9",
    "XjFyUwTpPW10",
    "FA8snJBROsBP",
    "Lqf2O0zFc9P8",
    "JSjBOhawckZG",
    "fJyraQBzEqwF",
    "bu1KYpplEzD6",
    "F1jF0uwcykKm",
    "ToBR2h4PwMIb",
    "DooXWxtQ1tjx",
    "mh50Nw3FOuUw",
    "67HF3GcqGkFf",
    "wxY_W3Fosi27",
    "kYDAmoF2d3cY",
    "Ol9Mt4nBJmsy",
    "Yg9frZOcFFMl",
    "pR_J5DWWkY0Z",
    "rtVkVEC4kvFI",
    "9UfjwuZIfEOl",
    "HaJOqUYV1Bnl",
    "6z7F6beaq3Ss",
    "st77keSoInwh",
    "epdlj7_Geu6o",
    "oggNTDgMSIi7",
    "79gCm6ojyAqA",
    "VTdSfgfUSTqI",
    "045YDho7iEeP",
    "YogpuJOuAJv2",
    "fumW2AyH1FtP",
    "KEhXEkMqcXRn",
    "5ZqQwjC9HCA4",
    "zIi0myRjEObv",
    "3TSArbBvqyZB",
    "mJExw2p2XqNK",
    "Ik_1mQ3Z9NcA",
    "PvyUTU8r5sjh",
    "k_l6zTssWSlH",
    "zqUs0JtvXVjh",
    "0t9JYNEsJWIz",
    "2IYbsVkEa2dD",
    "ZQVFNLiTq1s6",
    "wRsg9jFHqsSV",
    "iFH1r0Hm_V9I",
    "WsGdjVsBYZeV",
    "Ujtgl8RYXMih",
    "Frw4N18UHpHW",
    "rxzSsq4U0ITH",
    "qeS4uuA5HF8u",
};

int main() {
    int stIzhodnih = 0;
    char** izhodni = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%d: \"%s\"\n", i, izhodni[i]);
        free(izhodni[i]);
    }
    free(izhodni);

    return 0;
}
