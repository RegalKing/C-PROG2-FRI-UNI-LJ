
typedef struct _Vozlisce {
    char znak;
    struct _Vozlisce* naslednje;   // naslednik vozli"s"ca (NULL, "ce ga ni)
} Vozlisce;

char* sestavi(Vozlisce* zacetek);
