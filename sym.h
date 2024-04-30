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
  _opr,
  _id,
} nodeEnum;

typedef struct {
  int value;
} _conIntNodeType;

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
    _idNodeType id;
    _oprNodeType opr;
  };
} nodeType;

extern unsigned long sym_hash(char *str);

extern int sym[MAX_SYMBOLS];