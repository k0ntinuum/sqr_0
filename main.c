#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "text.c"
#include "print.c"
#include "random.c"
#include "key.c"
#include "compute.c"



int main() {
    int k[K][K];int x[X];int y[X];int w[X];int key_start = 0;int p[P];int c[C];int d[P];
    int m[K];int s[K];int bit = 0;int decoded_bit = 0;
    for (int i = 0; i < K; i++) m[i] = 1;
    for (int i = 0; i < K; i++) s[i] = 0;
    //hide_cursor();
    //cls();
    create_key(k);
    print_key(k);
    randomize_plain(p);
    //randomize_word(x);
    //apply_key(k,x,y);
    printf("\n\n");
    //bit = arc4random_uniform(B);
    //print_bit(bit);
    //create_codeword(k,m,bit,x,y);
    //for (int i = )
    encode_plain(k,m,s,p,c);
    decode_cipher(k,m,s,c,d);
    printf("\n");
    print_v(p,P);
    printf("\n");
    print_v(c,C);
    printf("\n");
    print_v(d,P);
    //decoded_bit = recover_bit(k,m,x);
    //print_bit(decoded_bit);

    // for (int s = 0; s < 100; s++ ) {
    //     printf("key = \n");
    //     create_key(k); 
    //     printf("\n\n");
    //     print_key(k,0);
    //     printf("\n\n");
    //     for (int i = 0; i < 1; i++ )  {
    //         randomize_p(p);
    //         encode_plaintext(k, key_start, p, c );
    //         decode_ciphertext(k, key_start, c, d);
    //         printf("  f ");print_v(p, P); printf(" = "); print_v(c,C);printf("\n");
    //         printf("  g ");print_v(c, C); printf(" = "); print_v(d,P);printf("\n\n");
    //     }
    //     //usleep(20000000);

    // }
}
      