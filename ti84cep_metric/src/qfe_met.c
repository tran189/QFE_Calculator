#include <ti/getcsc.h>
#include <ti/screen.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 32
#define OUTPUT_SIZE 32

float get_float(char* message_str) {
    char input_buffer[INPUT_SIZE];
    os_GetStringInput(message_str, input_buffer, INPUT_SIZE);
    os_NewLine();

    float val = (float) atof(input_buffer);
    return val;
}

float  qnh_n_elev_to_qfe(float qnh, float elev_m) {
	return qnh - (elev_m/9.3);
}

int main() {
    //intro and input
    os_ClrHome();
    printf("Welcome to MasiveFire's\nQFE calculator (metric)\n\n");
    float ref_qnh = get_float("Reference QNH (hPa): ");
    float targ_elev_m = get_float("Elevation (m): ");

    //clear screen and print input
    os_ClrHome();
    printf("Reference QNH: %.0f hPa\n", ref_qnh);
    printf("Elevation: %.0f m\n", targ_elev_m);

	//calculate and print qfe
	float targ_qfe = qnh_n_elev_to_qfe(ref_qnh, targ_elev_m);
    printf("QFE Setting: %.0f hPa\n", targ_qfe);

    //wait for button push before exit
    while (!os_GetCSC());
	return 0;
}