#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int getInt(int*, char [], char [], int , int);

int getFloat(float*, char[], char[], int, int);

int getChar(char*, char condition[], char error[], int rangeMinimum, int rangeMaximum);

int PedirString(char [], char [], char [], int , int );

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int utn_getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int utn_getLastName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);

int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);

int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int isValidSignedNumber(char* stringRecibido);

int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input);
int isValidTelephone(char* stringRecibido);

int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidDNI(char* stringRecibido);

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input);
int isValidCUIT(char* stringRecibido);

int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidEmail(char* stringRecibido);

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTexto(char* stringRecibido);

int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidAlphanumeric(char* stringRecibido);

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidChar(char charRecibido);

#endif // FUNCTIONS_H_INCLUDED
