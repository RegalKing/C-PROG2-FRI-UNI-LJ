
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
    return v(681, v(386, v(399, v(605, v(853, v(247, v(758, v(895, v(696, v(129, v(600, v(452, v(931, v(228, v(288, v(39, v(212, v(167, v(195, v(81, v(653, v(745, v(910, v(543, v(562, v(341, v(244, v(825, v(547, v(648, v(25, v(222, v(210, v(604, v(213, v(275, v(822, v(696, v(209, v(424, v(94, v(10, v(590, v(970, v(513, v(889, v(190, v(965, v(487, v(216, v(917, v(990, v(760, v(130, v(107, v(666, v(164, v(826, v(979, v(596, v(391, v(279, v(150, v(137, v(356, v(86, v(367, v(424, v(246, v(540, v(534, v(905, v(556, v(922, v(260, v(678, v(504, NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

Vozlisce* zgradiIndekse() {
    return v(1, v(3, v(4, v(7, v(8, v(9, v(10, v(11, v(12, v(13, v(14, v(15, v(17, v(19, v(20, v(21, v(23, v(24, v(25, v(27, v(28, v(29, v(30, v(31, v(32, v(33, v(34, v(35, v(36, v(37, v(38, v(39, v(40, v(41, v(42, v(43, v(44, v(45, v(46, v(47, v(48, v(49, v(50, v(51, v(52, v(53, v(54, v(55, v(56, v(57, v(58, v(59, v(60, v(61, v(62, v(63, v(64, v(65, v(66, v(67, v(68, v(69, v(70, v(71, v(72, v(73, v(74, v(75, v(76, NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
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
