#if defined(__cplusplus)
extern "C" {
#endif


#ifdef SWIG
%native(_wrap_MC_init) MC_init;
%native(_wrap_MC_about) MC_about;

%{
#include <stdbool.h>
extern PyObject *_wrap_MC_init(PyObject *self, PyObject *args);
extern PyObject *_wrap_MC_about(PyObject *self, PyObject *args);
%}

#else
#  include <stdbool.h>
#endif

extern double stretch_exponent_default;
extern double stretch_exponent;
extern LANGSPEC void stretch_ok(void);

extern double wobble_frequency_default;
extern double wobble_amplitude_default;
extern double wobble_frequency;
extern double wobble_amplitude;
extern LANGSPEC void wobble_ok(void);

extern double spectrumshift_shift_value_default;
extern double spectrumshift_shift_value;
extern LANGSPEC void spectrum_shift_ok(void);

extern double multiplyphase_phase_multiplier_default;
extern double multiplyphase_phase_multiplier;
extern bool multiplyphase_phase_random_default;
extern bool multiplyphase_phase_random;
extern LANGSPEC void multiply_phase_ok(void);

extern double derivateamp_amp_derivate_multiplier_default;
extern double derivateamp_amp_derivate_multiplier;
extern LANGSPEC void derivate_amp_ok(void);

extern double filter_lower_cutoff_default;
extern double filter_upper_cutoff_default;
extern double filter_sharpness_default;
extern double filter_lower_cutoff;
extern double filter_upper_cutoff;
extern double filter_sharpness;
extern LANGSPEC void filter_ok(void);

extern double invert_inversion_block_size_default;
extern double invert_inversion_block_size;
extern LANGSPEC void invert_ok(void);

extern double threshold_threshold_level_default;
extern bool threshold_remove_above_threshold_default;
extern double threshold_threshold_level;
extern bool threshold_remove_above_threshold;
extern LANGSPEC void threshold_ok(void);

extern LANGSPEC void keep_peaks_ok(void);

extern int blockswap_number_of_swaps_default;
extern double blockswap_block_size_default;
extern bool blockswap_old_version_with_error_default;
extern int blockswap_number_of_swaps;
extern double blockswap_block_size;
extern bool blockswap_old_version_with_error;
extern LANGSPEC void block_swap_ok(void);

extern double gain_amplitude_multiplier_default;
extern double gain_amplitude_multiplier;
extern LANGSPEC void gain_ok(void);

extern int combsplit_block_size_default;
extern int combsplit_number_of_files_default;
extern int combsplit_block_size;
extern int combsplit_number_of_files;
extern LANGSPEC void combsplit_ok(void);

extern LANGSPEC void split_real_imag_ok(void);

extern double mirror_mirror_frequency_default;
extern double mirror_mirror_frequency;
extern LANGSPEC void mirror_ok(void);

extern double amplitudephase_amplitude_multiplier_default;
extern double amplitudephase_amplitude_multiplier;
extern LANGSPEC void amplitude_phase_ok(void);


extern LANGSPEC void Phaseswap(void);

extern double crossover_switching_probability_default;
extern double crossover_switching_probability;
extern LANGSPEC void crossover_ok(void);



extern int analysis_duration_doubling_default;
extern int analysis_duration_doubling;
extern LANGSPEC void analysis_ok(void);


extern bool synthandsave_normalize_gain;


extern bool loadandmultiply_convolve;
extern bool loadandmultiply_correlate;
extern bool loadandmultiply_fun;
extern bool loadandmultiply_a_b;
extern bool loadandmultiply_phase_amp;
extern LANGSPEC char *load_and_multiply_ok(char *filename);

extern LANGSPEC void MC_init(void);

extern LANGSPEC void MC_play(void);
extern LANGSPEC void MC_stop(void);
extern LANGSPEC void MC_zoom(void);
extern LANGSPEC void MC_left(void);
extern LANGSPEC void MC_right(void);
extern LANGSPEC void MC_redrawWin(void);
extern LANGSPEC char *MC_loadAndAnalyze(char *filename);
extern LANGSPEC bool MC_isStereo(void);
extern LANGSPEC char *MC_synthAndSave(char *filename);


extern LANGSPEC void MC_undo(void);
extern LANGSPEC void MC_redo(void);
extern LANGSPEC char *MC_addUndo(void);
extern LANGSPEC void MC_resetUndo(void);
extern bool unlimited_undo;
extern bool enable_undo;

#if defined(__cplusplus)
   }
#endif
