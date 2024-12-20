
void apply_CA_rule(int f[K], int s, int x[X], int y[X]) {
	int val;
	for (int b = 0; b < X; b++) {
		val = 0;
		for (int i = 0 ; i < N ; i++) val += place_value[i]*x[(b + i)%X];
		y[b] = f[(s + val)%K];
	}
}
void apply_key(int k[K][K], int m[K], int s[K], int x[X], int y[X]) {
	int t[K][X] = {0};int loud = 1;
	for (int i = 0; i < X; i++) t[0][i] = x[i];
	for (int i = 1; i < K; i++) {
		if (m[i]) apply_CA_rule(k[i-1], s[i], t[i-1], t[i]);
		else for (int j = 0; j < X; j++) t[i][j] = t[i-1][j];
	}
	for (int i = 0; i < X; i++) y[i] = t[K-1][i];
	if (loud) print_calc(t);
}

void copy_word(int src[X],int tar[X]) {
	for (int i = 0; i < X; i++) tar[i] = src[i];
}

void apply_mask(int x[X], int y[X], int z[X]) {
	for (int i = 0; i < X; i++) z[i] = (x[i] + y[i])%B;
}
int parity(int x[X]) {
	int s = 0;
	for (int i = 0; i < X; i++) s += x[i];
	return s%B;
}

void create_codeword(int k[K][K],  int m[K], int s[K], int p, int x[X], int y[X] ) {
	int e[X] = {0},t[X] = {0}, loud = 1, val = 0;
	for (int i = 0; i < 100; i++) {
		randomize_word(e);
		apply_key(k, m, s, e, t);	
		//apply_mask(s, l, t);
		if (parity(t) == p) {
			if (loud) {
				printf("  random codeword = ");print_v(e, X);printf("\n");
				printf("  apply key       = ");print_v(t, X);printf("\n\n");
				//printf("  recall last     = ");print_v(l, X);printf("\n");
				//printf("  xor             = ");print_v(t, X);printf("\n");
				//for (int i = 0 ; i < X ; i++) val += place_value[i]*t[i%X];
				//printf("  val of xor      = %03d\n", val);
				//printf("  mod sum xor     = ");print_bit(p);printf("\n\n");

			}
			copy_word(e, x);
			copy_word(t, y);
			
			return;
		}
	}
	printf("failure to encode");
	return;
}
int recover_bit(int k[K][K], int m[K], int s[K], int x[X] ) {
	int y[X], loud = 1, val = 0;
	apply_key(k, m, s, x, y);	
	return parity(y);
}


void encode_plain(int k[K][K], int m[K],int s[K], int p[P], int c[C]) {
	int x[X];int y[X];int mode[K];int settings[K];
	for (int i = 0 ; i < K ; i++) mode[i] = m[i];
	for (int i = 0 ; i < K ; i++) settings[i] = s[i];
	for (int i = 0; i < P; i++) {
		create_codeword(k, mode, settings, p[i], x, y);
		for (int j = 0 ; j < X; j++) c[X*i + j] = x[j];
		for (int i = 0 ; i < K ; i++) mode[i] = y[i];
		for (int n = 0 ; n < K ; n++) settings[n] = (y[n] + settings[n])%K;
	}
}
void decode_cipher(int k[K][K], int m[K], int s[K], int c[P], int p[C]) {
	int x[X];int y[X];int mode[K];int settings[K];
	for (int i = 0 ; i < K ; i++) mode[i] = m[i];
	for (int i = 0 ; i < K ; i++) settings[i] = s[i];
	for (int i = 0; i < P; i++) {
		for (int j = 0 ; j < X; j++) x[j] = c[X*i + j];
		apply_key(k, mode, settings,  x, y);
		for (int n = 0 ; n < K ; n++) mode[n] = y[n];
		for (int n = 0 ; n < K ; n++) settings[n] = (y[n] + settings[n])%K;
		p[i] = parity(y);
	}
}







