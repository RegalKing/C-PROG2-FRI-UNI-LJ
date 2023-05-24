
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
    return v(74, v(734, v(239, v(575, v(620, v(455, v(768, v(154, v(946, v(141, v(224, v(602, v(493, v(849, v(222, v(802, v(979, v(458, v(380, v(152, v(588, v(59, v(632, v(464, v(561, v(142, v(828, v(939, v(202, v(764, v(774, v(379, v(493, v(24, v(589, v(68, v(639, v(732, v(971, v(861, v(493, v(865, v(672, v(597, v(130, v(572, v(139, v(371, v(211, v(766, v(489, v(710, v(202, v(679, v(865, v(929, v(134, v(196, v(520, v(624, v(286, v(45, v(435, v(556, v(84, v(784, v(443, v(614, v(685, v(694, v(67, v(377, v(991, v(845, v(570, v(43, v(625, v(358, v(367, v(817, v(7, v(162, v(437, v(537, v(882, v(981, v(707, v(330, v(789, v(477, v(456, v(59, v(685, v(378, v(948, v(680, v(931, v(602, v(917, NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

Vozlisce* zgradiIndekse() {
    return v(0, v(1, v(2, v(3, v(4, v(5, v(6, v(7, v(8, v(9, v(10, v(11, v(13, v(14, v(17, v(18, v(19, v(21, v(22, v(23, v(24, v(25, v(26, v(27, v(28, v(29, v(30, v(31, v(32, v(33, v(34, v(35, v(36, v(38, v(39, v(40, v(41, v(42, v(43, v(44, v(45, v(46, v(47, v(48, v(49, v(50, v(52, v(53, v(54, v(55, v(56, v(57, v(58, v(59, v(60, v(61, v(63, v(64, v(65, v(66, v(67, v(68, v(69, v(70, v(71, v(72, v(73, v(75, v(76, v(77, v(78, v(79, v(80, v(81, v(82, v(83, v(84, v(85, v(86, v(87, v(90, v(91, v(92, v(93, v(95, v(96, v(98, NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
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
