//DISCLAIMER
//i am not a ppl, formulas taken from chuck's
//if you use this in a real plane you may die

//qfe calculator by MassiveFire
//base unit used in calculations will be metric
//there will launch flags to set altitude units
	//-i/-I: imperial altitude in ft
	//-m/-M: metric altitude in meters
	//1 ft = 0.3048 m exactly
//pressure units will always be in Hpa
//calculations will be done in float
	//may update to double in future if necessary
//TODO: port to ti-84
//TODO: add -d debug flag (if you have time)

#include <stdio.h>
#include <string.h>

float ft_to_m(float feet) {
	return 0.3048*feet;
}

float  qnh_n_elev_to_qfe(float qnh, float elev_m) {
	return qnh - (elev_m/9.3);
}

typedef enum {metric, imperial} units_t;

int main(int argc, char** argv) {
	//setting the appropriate unit
	units_t input_units = imperial;
	if (argc >= 2) {
		if (argc > 2) {
			printf("Too many arguments!\n");
			return 0;
		}
		if (strncmp(argv[1], "-m", 2) == 0 || strncmp(argv[1], "-M", 2) == 0) {
			input_units = metric;
		} else if (strncmp(argv[1], "-i", 2) == 0, strncmp(argv[1], "-I", 2) == 0) {
			input_units = imperial;
		} else {
			printf("Undefined argument!\n");
			return 0;
		}
	}
	//input vars
	float base_qnh;
	float targ_elev_m;
	//intro and input
	printf("Welcome to MasiveFire's QFE calculator (%s)\n",
		(input_units == metric)?"metric":"imperial");
	printf("Airfield QNH:\t\t");
	scanf("%f", &base_qnh);
	printf("Target elevation (%s):\t", (input_units == metric)?"m":"ft");
	scanf("%f", &targ_elev_m);
	if (input_units == imperial) {
		targ_elev_m = ft_to_m(targ_elev_m);
	}
	//calculate and print qfe
	float targ_qfe = qnh_n_elev_to_qfe(base_qnh, targ_elev_m);
	printf("Target QFE:\t\t%.0f\n", targ_qfe);
	return 0;
}
