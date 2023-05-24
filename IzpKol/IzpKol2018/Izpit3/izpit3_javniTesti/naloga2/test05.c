
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
    return v(393, v(626, v(859, v(391, v(313, v(101, v(178, v(964, v(851, v(645, v(439, v(89, v(748, v(535, v(289, v(447, v(968, v(215, v(296, v(844, v(992, v(292, v(389, v(741, v(343, v(955, v(798, v(973, v(848, v(316, v(507, v(84, v(267, v(747, v(61, v(9, v(383, v(381, v(97, v(955, v(681, v(640, v(699, v(876, v(899, v(251, v(300, v(212, v(821, v(985, v(938, v(851, v(817, v(492, v(39, v(793, v(602, v(567, v(714, v(680, v(370, v(374, v(72, v(145, v(523, v(795, v(386, v(603, v(542, v(949, v(786, v(587, v(295, v(338, v(655, v(429, v(159, v(407, v(342, v(694, v(505, v(397, v(899, v(326, v(157, v(74, v(733, v(300, v(797, v(502, v(55, v(182, v(854, v(33, v(690, v(190, v(810, v(701, v(828, v(98, v(546, v(38, v(604, v(451, v(902, v(904, v(729, v(549, v(6, v(266, v(104, v(916, v(11, v(988, v(330, v(384, v(277, v(370, v(127, v(956, v(663, v(459, v(485, v(845, v(98, v(220, v(910, v(276, v(260, v(634, v(830, v(599, v(596, v(299, v(444, v(348, v(233, v(352, v(950, v(85, v(406, v(982, v(872, v(675, v(400, v(972, v(731, v(422, v(840, v(39, v(467, v(297, v(604, v(982, v(174, v(627, v(2, v(601, v(271, v(376, v(383, v(526, v(79, v(120, NULL))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

Vozlisce* zgradiIndekse() {
    return v(15, v(31, v(37, v(42, v(47, v(51, v(66, v(92, v(94, v(126, v(133, v(134, v(153, v(156, NULL))))))))))))));
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
