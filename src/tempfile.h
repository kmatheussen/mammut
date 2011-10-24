
/* tempfile.h taken from ceres. */

struct TempFile{
  struct TempFile *next;
  FILE *file;
  //void *das_file;
  char *name;
  int status;
};

extern LANGSPEC void TF_freezePath(void);
extern LANGSPEC void TF_unfreezePath(void);
extern LANGSPEC void TF_delete(struct TempFile *tf);
extern LANGSPEC void TF_cleanup(void);
extern LANGSPEC void TF_cleanup_exit(void);
extern LANGSPEC struct TempFile *TF_new(char *firstname);
extern LANGSPEC struct TempFile *TF_makeCopy(char *firstname,struct TempFile *from);
extern LANGSPEC bool TF_read(struct TempFile *tf,void *dest,size_t size1,size_t size2);
extern LANGSPEC bool TF_write(struct TempFile *tf,void *source,size_t size1,size_t size2);

//extern LANGSPEC int TF_write(struct Tempfile *tf,void *ptr,size_t size);
//extern LANGSPEC int TF_read(struct Tempfile *tf,void *ptr,size_t size);


extern LANGSPEC void create_tempfile(void);

