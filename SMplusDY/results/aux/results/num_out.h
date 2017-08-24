#ifndef __NUM_OUT_p20_p8a12a15
#define __NUM_OUT_p20_p8a12a15

#include<stdlib.h>
#include<string.h> 
#include<math.h>

#include"nType.h"

#define maxNp 20

extern  int    FError;

extern const int nin_p20_p8a12a15;
extern const int nout_p20_p8a12a15;
extern const int nprc_p20_p8a12a15;
extern const int nvar_p20_p8a12a15;
extern const int nfunc_p20_p8a12a15;

extern char * pinf_p20_p8a12a15(int nsub,int nprtcl,REAL* pmass,int*num);
extern int   pinfAux_p20_p8a12a15(int nsub, int nprtcl,int *spin2, int* color,int*neutral);
extern char * varName_p20_p8a12a15[];

extern double sqme_p20_p8a12a15(int nsub,double GG, REAL * momenta, REAL*cb_coeff,int * err);
extern int calcFunc_p20_p8a12a15(void);
extern double BWrange_p20_p8a12a15;
extern int twidth_p20_p8a12a15, gtwidth_p20_p8a12a15, gswidth_p20_p8a12a15;
extern double (*aWidth_p20_p8a12a15)(char *);
extern REAL va_p20_p8a12a15[];

extern  char * den_info_p20_p8a12a15(int nsub, int n, int * mass, int * width,int *pnum);


typedef  struct  { int pow; int nC; int * chains;} colorBasis;

extern colorBasis cb_p20_p8a12a15[];  

extern double (*aWidth_p20_p8a12a15)(char *);

#ifndef  __CALCHEP_INTERFACE__
#define  __CALCHEP_INTERFACE__
typedef struct CalcHEP_interface
{

  int forceUG;
  char * CALCHEP;

  int nvar;
  int nfunc;
  char ** varName;
  REAL * va;
  
  int nin;
  int nout;
  int nprc;
  char* (*pinf)(int, int , REAL*,int *);
  int  (*pinfAux)(int, int,int *,int*,int*);
  char** polarized;
  int (*calcFunc)(void);
  double * BWrange;
  int    * twidth;    
  int *   gtwidth;
  int *   gswidth;
  double (**aWidth)(char *);

  double (*sqme)(int,double,REAL*,REAL*,int*);

  char * (*den_info)(int, int, int *, int*,int*);
  colorBasis *cb;  
} CalcHEP_interface;

extern int    jobInit(CalcHEP_interface * interface);
extern int    jobInState(int nProc, double P1, double P2, char* strf1, char*strf2);
extern int    jobCut2(char * par,double min,  double max);
extern int    jobCutMin(char * par,double min);
extern int    jobCutMax(char * par,double max);
extern void   jobCutDel(void);
extern int    jobHist(double min, char * par, double max);
extern void   jobHistDel(void);
extern double jobVegas(int nSess,int nCalls,int clear,int*err_,double*dI,double*chi2);
#endif

extern CalcHEP_interface interface_p20_p8a12a15;
extern CalcHEP_interface * PtrInterface_p20_p8a12a15;

extern void link_process(CalcHEP_interface * interface);

extern  int    OnlyTEQ0;

#define  DENOMINATOR_ERROR   2
#endif
