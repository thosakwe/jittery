grammar Jittery;

compilationUnit: topLevel*;

topLevel:
    fnDecl
    | stmt
;

fnDecl: 'fn' name=ID '(' ((params+=ID ',')* params+=ID)? ')' ':' stmt*  'end';

stmts: stmt*;

stmt:
    'let' ID '=' expr #VarDeclStmt
    | 'if' condition=expr ':' ifPredicate=stmts ('else' 'if' elseIf)*  ('else' elsePredicate=stmts)? 'end' #IfStmt
    | 'while' condition=expr stmts 'end' #WhileStmt
    | 'for' itemName=ID (',' indexName=ID)? 'in' expr ':' stmts 'end' #ForStmt
    | 'throw' expr #ThrowStmt
    | 'return' expr #ReturnStmt
    | ID '=' expr #IdAssnStmt
    | expr #ExprStmt
;

elseIf: condition=expr ':' predicate=stmt*;

expr:
    'true' #TrueExpr
    | 'false' #FalseExpr
    | ID #IdExpr
    | FLOAT #FloatExpr
    | INT #IntExpr
    | STRING #StringExpr
    | target=expr '(' ((arguments+=expr ',')* arguments+=expr)? ')' #CallExpr
    | 'range' from=expr 'to' to=expr #RangeExpr
    | 'if' condition=expr 'then' then=expr 'else' otherwise=expr #CondExpr
    | left=expr op=('*' |'/' | '%') right=expr #MulDivModExpr
    | left=expr op=('+' |'-') right=expr #AddSubExpr
    | left=expr op=('==' |'!=') right=expr #BoolEqExpr
    //| '(' expr ')' #ParenthesizedExpr
;

COMMENT: '//' (~'\n')* -> skip;
WS: [ \n\r\t]+ -> skip;
FLOAT: '-'? [0-9]+ ('.' [0-9]+);
INT: '-'? [0-9]+;
STRING: '\'' (('\\\'') | ~('\''))* '\'';
ID: [A-Za-z_][A-Za-z0-9_]*;