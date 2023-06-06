#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001
int _P[] = {1103, 104, 7046, 5659, 5751, 607, 6881, 4511, 967, 2343, 9186, 8935, 8570, 9044, 3498, 9185, 9290, 8299, 5772, 6679, 4712, 8664, 1373, 9171, 1372, 2131, 7599, 4921, 6455, 8514, 2262, 7173, 2709, 7568, 5795, 3418, 5703, 1392, 2979, 7176, 8534, 4163, 4291, 6151, 9110, 227, 2389, 3487, 160, 6652, 6616, 9386, 3360, 3960, 3198, 2112, 4684, 3652, 4126, 3250, 5270, 12, 768, 5082, 608, 9920, 7738, 2338, 6556, 7119, 132, 3448, 7683, 3380, 7430, 8877, 5241, 1600, 1038, 9866, 5599, 6442, 8056, 6772, 983, 7663, 1674, 4121, 8735, 7457, 4455, 8337, 8102, 580, 5195, 9860, 1589, 8764, 6417, 5813, 3822, 2958, 9549, 9701, 4202, 9266, 8433, 3439, 3247, 1641, 3788, 6198, 5975, 8091, 4794, 6764, 5444, 4948, 9968, 9829, 7905, 4136, 7208, 2993, 1363, 5555, 2930, 5297, 2600, 5761, 8007, 8656, 4, 2822, 7938, 5376, 9217, 8959, 7343, 6643, 9173, 2478, 3927, 6316, 2077, 9328, 923, 1952, 1966, 3081, 741, 2408, 9106, 959, 8435, 9740, 2204, 6051, 4659, 8101, 864, 2182, 1814, 7748, 212, 4523, 7029, 7676, 234, 9191, 2961, 1568, 9607, 1349, 8835, 1577, 555, 6609, 3716, 7203, 3438, 4025, 563, 5222, 88, 1481, 2579, 6388, 3765, 3152, 6499, 498, 2083, 7992, 9720, 4672, 4945, 7, 8293, 1279, 6329, 5240, 7093, 8354, 9120, 3983, 8290, 9116, 7409, 1033, 9854, 689, 6857, 4626, 275, 6100, 4377, 733, 2781, 256, 2226, 961, 9828, 7631, 8793, 8162, 3426, 4839, 6420, 6305, 8666, 8526, 1848, 2787, 3424, 6995, 993, 4838, 4420, 1306, 8927, 7969, 3904, 654, 7919, 7895, 8746, 1241, 1917, 8095, 2081, 3447, 1357, 413, 3458, 268, 3101, 8034, 968, 5914, 7787, 2075, 401, 9624, 9394, 9017, 1406, 3816, 9234, 5932, 8878, 1603, 2784, 5482, 2862, 5854, 6785, 3016, 5666, 2679, 6152, 8053, 3910, 6281, 2091, 3284, 5543, 9574, 5052, 1499, 920, 176, 4740, 1839, 4490, 2424, 1179, 60, 8510, 6172, 8811, 9535, 9317, 5789, 2151, 7036, 8411, 7922, 557, 7613, 5689, 8219, 4051, 1183, 4151, 2507, 1505, 2379, 4361, 3131, 9880, 3309, 9578, 4685, 843, 6134, 5488, 5308, 9881, 1667, 9875, 6406, 3310, 2177, 8178, 8218, 9934, 8424, 6563, 6341, 3359, 1914, 3736, 4700, 8214, 7573, 8547, 7287, 4481, 7432, 5206, 1387, 2593, 6011, 1825, 1905, 9718, 6844, 465, 1025, 7377, 5837, 4774, 8703, 6713, 2866, 728, 4079, 6969, 9958, 1679, 9618, 8960, 1311, 6362, 6220, 6120, 8377, 2243, 8627, 2216, 4060, 8830, 6742, 5114, 7113, 9767, 6463, 1196, 208, 6464, 1063, 3820, 1422, 2285, 5585, 5407, 1871, 8421, 7240, 7585, 7110, 3580, 5121, 4494, 3316, 1084, 9945, 7475, 2872, 4176, 3940, 4419, 5691, 6394, 9840, 1826, 8417, 1118, 3529, 5420, 1108, 1554, 5263, 3727, 6248, 5749, 7491, 4675, 3303, 9537, 9654, 2105, 3673, 8519, 5728, 2555, 3989, 3618, 4005, 9742, 6781, 7542, 4231, 8458, 8722, 6862, 2620, 8260, 6337, 5567, 527, 5760, 267, 3847, 2798, 5193, 2868, 7728, 757, 3894, 6787, 4795, 5466, 1350, 7789, 6275, 6009, 6846, 5437, 6325, 9112, 9012, 4533, 6236, 2272, 9984, 605, 7334, 5907, 7292, 2314, 5487, 2070, 5375, 4544, 9763, 1298, 1334, 886, 299, 9210, 8815, 5620, 1817, 7367, 6811, 341, 7532, 199, 9465, 7558, 8126, 1842, 8995, 8495, 9502, 5552, 4841, 5807, 1541, 1970, 9319, 5291, 4418, 4138, 3137, 9659, 5624, 4655, 4721, 2783, 3592, 3136, 6532, 337, 4861, 911, 2561, 4857, 800, 8480, 5670, 4326, 2904, 2562, 7288, 9556, 3728, 8177, 7694, 2311, 7660, 8348, 1480, 1802, 9835, 7743, 9349, 5708, 6462, 4489, 2113, 9318, 5087, 7788, 7878, 2229, 3947, 8612, 8040, 5374, 9418, 1663, 7682, 1300, 8248, 6818, 3691, 8617, 5453, 458, 2, 4596, 5788, 5084, 4306, 1977, 8183, 8477, 8506, 7520, 4335, 7039, 3401, 2008, 4727, 5353, 8491, 7445, 124, 1464, 8962, 8893, 4981, 5318, 5551, 4810, 564, 7778, 8344, 631, 11, 3573, 7648, 952, 6972, 4456, 8282, 2768, 5287, 2518, 3462, 1743, 1888, 231, 1661, 9689, 1012, 153, 1019, 7412, 1493, 4237, 140, 9239, 2925, 3546, 4823, 7536, 9889, 4520, 5930, 5742, 1775, 8432, 3244, 510, 2589, 2095, 129, 8456, 3542, 9097, 5107, 453, 808, 8950, 7802, 4722, 5897, 376, 2594, 1847, 7122, 3818, 338, 7359, 7284, 2738, 2540, 9058, 9961, 6094, 4750, 9397, 1796, 937, 1773, 1672, 8502, 2659, 3614, 2485, 4623, 4242, 7382, 3169, 3019, 5893, 20, 2964, 3500, 4590, 6370, 2699, 170, 7179, 2614, 6538, 1824, 287, 7654, 9354, 8029, 3099, 3694, 2835, 6839, 746, 1260, 5687, 1895, 5505, 1214, 5998, 4781, 5254, 9780, 5365, 102, 5981, 4405, 5312, 1077, 6424, 5402, 2800, 670, 4871, 9079, 7692, 8190, 5159, 5245, 4260, 3833, 2028, 7896, 9496, 5665, 4087, 1523, 7214, 7053, 6886, 832, 3049, 5176, 6871, 7515, 1051, 2551, 680, 3379, 3273, 2850, 8767, 7399, 8674, 5209, 3657, 1479, 7331, 3686, 7164, 8655, 7579, 1993, 9510, 2277, 3413, 5310, 9979, 5503, 9274, 5462, 5962, 641, 3488, 4031, 3710, 7771, 471, 8970, 6421, 4052, 474, 2956, 7967, 49, 7988, 6590, 3839, 9457, 2180, 2976, 9864, 6848, 908, 9163, 408, 6093, 3227, 7434, 3642, 9529, 9670, 3080, 3707, 834, 7944, 8013, 2007, 3451, 4713, 9043, 2047, 6559, 867, 762, 6297, 7061, 3338, 6501, 6182, 9999, 2947, 8621, 3603, 9622, 4299, 6206, 8226, 7193, 6232, 1792, 5140, 7915, 38, 833, 6968, 7855, 5061, 8940, 2214, 8530, 3778, 5033, 5126, 2756, 3420, 8150, 5655, 7680, 7444, 3134, 772, 6528, 5988, 1617, 9371, 2759, 6662, 7911, 1965, 4606, 2970, 1314, 2560, 2671, 2747, 4942, 2440, 415, 9887, 770, 2896, 998, 9399, 3001, 4775, 1909, 9797, 9641, 3463, 6892, 8721, 5410, 8209};
int _RAZREDI[] = {0, 1, 2, 3, 4, 5, 4, 1, 6, 4, 7, 8, 0, 4, 9, 10, 11, 12, 9, 13, 7, 14, 15, 16, 5, 17, 18, 19, 20, 21, 15, 22, 23, 24, 25, 8, 26, 27, 13, 5, 28, 10, 29, 30, 31, 32, 33, 34, 35, 33, 36, 26, 5, 4, 37, 38, 23, 7, 9, 39, 5, 40, 41, 8, 42, 9, 43, 43, 31, 44, 45, 46, 1, 47, 48, 49, 32, 50, 51, 0, 33, 47, 52, 28, 53, 54, 1, 55, 56, 57, 58, 37, 59, 60, 61, 62, 63, 8, 23, 64, 65, 66, 67, 43, 5, 68, 69, 70, 71, 31, 72, 73, 74, 75, 76, 8, 77, 78, 79, 80, 81, 80, 65, 82, 83, 84, 85, 86, 87, 88, 8, 89, 90, 91, 10, 43, 92, 10, 93, 94, 8, 95, 96, 97, 13, 28, 98, 4, 7, 5, 99, 5, 94, 100, 101, 50, 88, 102, 51, 94, 5, 103, 84, 104, 105, 106, 9, 67, 107, 108, 109, 110, 4, 111, 112, 113, 114, 115, 116, 117, 118, 119, 78, 120, 91, 4, 5, 121, 9, 122, 123, 124, 90, 125, 126, 127, 128, 129, 49, 88, 8, 130, 68, 131, 132, 133, 134, 100, 135, 136, 137, 138, 87, 58, 139, 140, 44, 141, 142, 143, 144, 145, 146, 147, 148, 9, 42, 149, 36, 150, 151, 152, 153, 154, 4, 155, 156, 157, 158, 9, 28, 159, 7, 160, 80, 161, 115, 32, 162, 163, 164, 165, 159, 39, 2, 121, 166, 167, 168, 169, 71, 170, 87, 171, 172, 173, 174, 175, 131, 155, 176, 176, 177, 102, 53, 178, 179, 180, 28, 181, 182, 140, 160, 9, 183, 13, 179, 184, 52, 9, 185, 111, 6, 186, 187, 188, 189, 87, 190, 191, 146, 4, 13, 192, 15, 193, 92, 35, 194, 195, 196, 136, 197, 4, 198, 199, 178, 200, 201, 202, 203, 204, 69, 205, 206, 207, 28, 208, 209, 210, 61, 211, 212, 213, 214, 215, 216, 217, 218, 219, 58, 207, 220, 221, 202, 39, 222, 223, 112, 211, 10, 224, 225, 42, 226, 36, 227, 144, 228, 213, 152, 146, 229, 230, 231, 65, 232, 233, 198, 234, 95, 235, 236, 237, 238, 9, 239, 90, 240, 241, 12, 4, 242, 243, 244, 245, 246, 4, 247, 248, 249, 250, 251, 252, 253, 254, 75, 255, 256, 257, 258, 259, 260, 232, 261, 43, 262, 263, 264, 265, 266, 267, 152, 268, 9, 8, 175, 269, 270, 77, 271, 272, 273, 17, 274, 275, 159, 276, 277, 278, 279, 87, 184, 217, 280, 264, 238, 230, 281, 282, 84, 283, 71, 284, 285, 286, 287, 239, 288, 289, 9, 290, 130, 265, 291, 292, 39, 238, 293, 23, 32, 4, 294, 295, 249, 296, 297, 277, 298, 94, 299, 300, 94, 301, 302, 118, 15, 303, 304, 2, 305, 306, 307, 308, 309, 237, 310, 311, 312, 313, 314, 315, 316, 317, 318, 200, 0, 319, 320, 321, 322, 246, 47, 323, 24, 324, 80, 325, 326, 327, 328, 329, 23, 330, 16, 135, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 263, 240, 210, 97, 70, 342, 9, 343, 207, 344, 345, 5, 346, 347, 24, 348, 19, 349, 152, 350, 351, 352, 329, 31, 353, 354, 34, 355, 356, 69, 357, 358, 359, 225, 328, 4, 360, 361, 362, 363, 121, 364, 365, 366, 367, 368, 28, 369, 61, 370, 237, 371, 15, 372, 373, 374, 375, 376, 377, 70, 378, 247, 84, 80, 52, 379, 133, 380, 381, 382, 383, 384, 385, 386, 387, 320, 388, 389, 390, 391, 74, 121, 392, 4, 393, 394, 9, 395, 226, 396, 397, 398, 84, 399, 400, 28, 401, 402, 50, 403, 404, 130, 405, 406, 337, 407, 408, 357, 319, 409, 410, 411, 139, 412, 54, 413, 414, 415, 416, 417, 418, 419, 181, 147, 420, 265, 365, 421, 422, 423, 238, 338, 424, 425, 426, 14, 78, 427, 428, 4, 429, 379, 430, 431, 9, 262, 4, 150, 111, 152, 432, 433, 233, 434, 435, 137, 436, 44, 437, 438, 439, 143, 440, 78, 441, 442, 64, 311, 443, 444, 445, 49, 376, 446, 447, 448, 159, 233, 65, 202, 449, 450, 451, 152, 452, 453, 454, 455, 456, 457, 458, 308, 459, 287, 460, 461, 206, 462, 463, 464, 465, 466, 467, 24, 200, 468, 171, 469, 313, 470, 471, 472, 4, 473, 121, 1, 123, 474, 475, 476, 477, 9, 344, 478, 479, 480, 481, 482, 483, 475, 484, 485, 486, 487, 488, 489, 366, 339, 490, 491, 492, 493, 78, 494, 345, 9, 200, 495, 496, 442, 497, 489, 498, 88, 15, 499, 500, 501, 502, 503, 8, 504, 111, 190, 69, 505, 506, 507, 508, 509, 510, 511, 512, 5, 513, 514, 515, 516, 223, 517, 200, 114, 518, 519, 520, 99, 521, 386, 319, 5, 522, 523, 524, 77, 525, 95, 526, 439, 527, 385, 528, 529, 530, 58, 531, 202, 3, 154, 532, 533, 534, 420, 535, 536, 338, 537, 532, 13, 538, 148, 65, 539, 39, 540, 541, 542, 543, 414, 544, 8, 365, 545, 98, 19, 546, 136, 547, 262, 548, 549, 74, 124, 550, 270, 58, 551, 552, 5, 553, 554, 200, 5, 555};
int _ST_VOZLISC = sizeof(_RAZREDI) / sizeof(_RAZREDI[0]);
#define  _ST_RAZREDOV (sizeof(_P) / sizeof(_P[0]))
Vozlisce* _I2V[_ST_RAZREDOV];
bool _POBRISAN[_M];

Vozlisce* _ustvari() {
    Vozlisce* zacetek = NULL;
    Vozlisce* prej = NULL;
    int zadnjiRazred = -1;

    for (int i = 0; i < _ST_VOZLISC; i++) {
        Vozlisce* v = calloc(1, sizeof(Vozlisce));
        int r = _RAZREDI[i];
        if (r > zadnjiRazred) {
            zadnjiRazred = r;
            v->p = malloc(sizeof(int));
            *v->p = _P[r];
            _I2V[r] = v;
        } else {
            v->p = _I2V[r]->p;
        }
        if (i == 0) {
            zacetek = v;
        } else {
            prej->naslednje = v;
        }
        prej = v;
    }
    return zacetek;
}

void _izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        printf("%s%d", (w == v ? "" : ", "), *w->p);
        w = w->naslednje;
    }
    printf("]\n");
}

void _preveriIstovetnost(Vozlisce* v) {
    int i = 0;
    for (Vozlisce* w = v; w != NULL; w = w->naslednje) {
        printf("%d", w == _I2V[i]);
        i++;
    }
    printf("\n");
}

void _pocisti(Vozlisce* v) {
    if (v != NULL) {
        _pocisti(v->naslednje);
        int pp = *v->p;
        if (!_POBRISAN[pp]) {
            free(v->p);
            v->p = NULL;
            _POBRISAN[pp] = true;
        }
        free(v);
    }
}

int main() {
    Vozlisce* v = _ustvari();

    printf("Prej:\n");
    _izpisi(v);
    printf("\n");

    izlociDuplikate(v);

    printf("Potem:\n");
    _izpisi(v);
    printf("\n");

    printf("Istovetnost ohranjenih vozlisc:\n");
    _preveriIstovetnost(v);

    _pocisti(v);

    return 0;
}