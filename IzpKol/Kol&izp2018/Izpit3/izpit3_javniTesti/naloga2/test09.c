
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
    return v(895, v(188, v(263, v(323, v(734, v(672, v(508, v(854, v(806, v(56, v(21, v(833, v(496, v(599, v(430, v(995, v(325, v(786, v(817, v(781, v(790, v(605, v(846, v(822, v(848, v(511, v(941, v(930, v(239, v(897, v(139, v(247, v(439, v(750, v(832, v(904, v(36, v(517, v(175, v(185, v(453, v(121, v(291, v(72, v(452, v(2, v(292, v(505, v(830, v(85, v(925, v(911, v(343, v(106, v(18, v(436, v(474, v(272, v(275, v(331, v(49, v(615, v(261, v(563, v(259, v(928, v(666, v(146, v(828, v(936, v(880, v(658, v(1000, v(407, v(722, v(33, v(902, v(104, v(446, v(350, v(459, v(764, v(149, v(94, v(223, v(931, v(428, v(939, v(213, v(497, v(339, v(531, v(369, v(820, v(78, v(292, v(862, v(635, v(872, v(589, v(477, v(108, v(173, v(223, v(432, v(571, v(792, v(479, v(43, v(516, v(580, v(859, v(695, v(999, v(718, v(585, v(712, v(626, v(661, v(634, v(47, v(423, v(115, v(151, v(273, v(677, v(290, v(938, v(181, NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

Vozlisce* zgradiIndekse() {
    return v(0, v(2, v(4, v(6, v(7, v(8, v(9, v(10, v(14, v(19, v(22, v(23, v(28, v(36, v(37, v(40, v(46, v(50, v(53, v(56, v(63, v(64, v(65, v(67, v(72, v(74, v(75, v(78, v(79, v(84, v(85, v(86, v(87, v(91, v(92, v(96, v(98, v(99, v(101, v(104, v(105, v(109, v(111, v(113, v(118, v(122, v(124, v(126, NULL))))))))))))))))))))))))))))))))))))))))))))))));
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
