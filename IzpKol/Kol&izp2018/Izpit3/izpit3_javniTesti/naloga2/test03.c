
#include "naloga2.h"

Vozlisce* v(int podatek, Vozlisce* naslednje) {
    Vozlisce* vozlisce = malloc(sizeof(Vozlisce));
    vozlisce->podatek = podatek;
    vozlisce->naslednje = naslednje;
    return vozlisce;
}

void izpisi(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    printf("[");
    while (p != NULL) {
        if (p != zacetek) {
            printf(", ");
        }
        printf("%d", p->podatek);
        p = p->naslednje;
    }
    printf("]\n");
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->naslednje);
        free(zacetek);
    }
}

Vozlisce* zgradiOsnovo() {
    return v(58, v(705, v(630, v(837, v(430, v(626, v(705, v(690, v(90, v(12, v(322, v(49, v(914, v(955, v(523, v(528, v(928, v(7, v(347, v(490, v(770, v(36, v(29, v(542, v(215, v(314, v(444, v(703, v(823, v(163, v(737, v(847, v(204, v(491, v(856, v(816, v(147, v(948, v(176, v(105, v(516, v(886, v(848, v(444, v(879, v(662, v(222, v(616, v(55, v(263, v(380, v(918, v(907, v(601, v(759, v(54, v(594, v(618, v(12, v(84, v(907, v(628, v(763, v(675, v(860, v(836, v(660, v(539, v(147, v(801, v(865, v(528, v(41, v(116, v(855, v(662, v(666, v(611, v(66, v(760, v(502, v(556, v(180, v(63, v(247, v(562, v(420, v(950, v(504, v(111, v(740, v(374, v(908, v(936, v(225, v(825, v(757, v(865, v(706, v(168, v(342, v(965, v(719, v(63, v(304, v(848, v(254, v(142, v(420, v(238, v(735, v(988, v(689, v(761, v(604, v(808, v(107, v(640, v(404, v(638, v(2, v(924, v(570, v(192, v(610, v(542, NULL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

Vozlisce* zgradiIndekse() {
    return v(32, NULL);
}

int __main__() {
    Vozlisce* osnova = zgradiOsnovo();
    Vozlisce* indeksi = zgradiIndekse();
    Vozlisce* rezultat = odstrani(osnova, indeksi);

    izpisi(rezultat);

    pocisti(indeksi);
    pocisti(rezultat);

    exit(0);
    return 0;
}
