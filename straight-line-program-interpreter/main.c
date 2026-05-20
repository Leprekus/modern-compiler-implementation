typedef const char *string;
typedef struct Stm_ *Stm;
typedef struct Exp_ *Exp;
typedef struct ExpList_ *ExpList;
typedef enum { ADD, SUB, MUL, DIV } BinOp;

// PRODUCTIONS - grammar rules
struct Stmt_ {
	enum { COMPOUND, ASSIGN, PRINT } kind;
	union {
		struct { Stm s1, s2; } compound;
		struct { string id; Exp e; } assign;
		struct { ExpList exps; } print;
	} u;
};
Stm stmt_compound(Stm s1, Stm s2);
Stm stmt_assign(string id, Exp expr);
Stm stmt_print(ExpList exps);

struct Exp_ {
	enum { ID, NUM, OP, ESEQ } kind;
	union {
		string id;
		int num;
		struct { Exp e1; BinOp op; Exp e2; } op;
		struct { Stm s; Exp e; } eseq;
	} u;
};
Exp exp_id(string id);
Exp exp_num(int num);
Exp exp_op(Exp e1, BinOp op, Exp e2);
Exp exp_eseq(Stm s, Exp e);

struct ExpList_ {
	enum { PAIR, LAST } kind;
	union {
		struct { Exp e; ExpList exps; } pair;
		Exp last;
	} u;
};
ExpList expList_pair(Exp e, ExpList exps);
ExpList expList_last(Exp last);

// CONSTRUCTORS - instantiate a grammar rule

int main() {


return 0;
}
