#define MAX_SYMBOLS 1000

typedef enum {
  _typeInt,
  _typeStr,
  _typeChar,
  _typeBoolean,
  _typeReal,
  _typeArray,
  _typeArrayIndex,
  _typeAssign,
  _typeAdd,
  _typeSub,
  _typeMul,
  _typeDiv,
  _typeMod,
  _typeAnd,
  _typeOr,
  _typeEE,
  _typeNE,
  _typeLT,
  _typeGT,
  _typeLE,
  _typeGE,
  _typeProgram,
  _typeMultId,
  _typeArgs,
  _typeDeclArray,
  _typeDecl,
  _typeDecls,
  _typeBody,
  _typeWrite,
  _typeRead,
  _typeForRange,
  _typeFor,
  _typeWhile,
  _typeIfElse,
  _typeIf,
  
} typeEnum;

typedef enum {
  _conInt, 
  _conStr, 
  _conBool,
  _conReal,
  _opr,
  _id,
} nodeEnum;

typedef struct {
  int value;
} _conIntNodeType;
typedef struct{
  float value;
} _conRealNodeType;
typedef struct {
  int value;
} _conBoolNodeType;

typedef struct {
  char *value;
} _conStrNodeType;

typedef struct {
  int i;
} _idNodeType;

typedef struct {
  typeEnum oper;
  int nops;
  struct NodeTypeTag **ops;
} _oprNodeType;

typedef struct NodeTypeTag {
  nodeEnum type;
  union {
    _conIntNodeType conInt;
    _conStrNodeType conStr;
    _conBoolNodeType conBool;
    _conRealNodeType conReal;
    _idNodeType id;
    _oprNodeType opr;
  };
} nodeType;


typedef enum {_dtEmpty, _dtInt, _dtReal, _dtChar, _dtBool, _dtIntArr, _dtRealArr, _dtCharArr, _dtBoolArr} dataType;

typedef struct {
  dataType dt;
  union {
    int intValue;
    char charValue;
    float realValue;
    char *charArrValue;
    int *intArrValue;
    float *realArrValue;
  };
  int declared;
  int arrSize;
} symNode;

extern unsigned long sym_hash(char *str);
extern char* sym_names[MAX_SYMBOLS];
extern symNode sym_table[MAX_SYMBOLS];

extern char* getName(int hash);
extern void setName(int hash, char *name);