

#ifdef __cplusplus
void juceplay_init(PropertiesFile *propertiesfile);
#endif

//extern LANGSPEC void juceplay_init();
extern LANGSPEC void juceplay_start();
extern LANGSPEC void juceplay_stop();
extern LANGSPEC void juceplay_prefs();

extern int jp_playpos;
extern bool jp_isplaying;

