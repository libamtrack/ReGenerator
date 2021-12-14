import re
from typing import Optional


class Expression:
    """
    Helper class used to break down (and validate) arithmetic expressions
    Examples of usage:
    >>> Expression('5')
    5
    >>> Expression('0xff')
    255
    >>> Expression('037')
    31
    >>> Expression('n')
    'n'

    >>> e = Expression('5*n')
    >>> e.left
    5
    >>> e.op
    '*'
    >>> e.right
    'n'

    >>> e = Expression('a+b-c')
    >>> e.left
    'a'
    >>> e.op
    '+'
    >>> e.right
    Expression('b-c')
    """

    operators = re.compile(r'[-+*/]')

    def __init__(self, expr: str = None):
        left, self.op, right = _split(expr)
        self.left = Expression(left)
        self.right = Expression(right)

    def __new__(cls, expr: str = None):
        """
        Thanks to this method, the Expression constructor can return
        an int, a string, None, or an Expression object depending
        on what kind of expression is passed to it.
        :param expr: string representation of an expression
        """
        expr = expr.strip() if expr is not None else ''
        if not expr:
            return None

        if cls.operators.search(expr) is not None:
            return super().__new__(cls)

        try:
            if expr.startswith('0x'):
                return int(expr, 16)
            elif expr[0] == '0':
                return int(expr, 8)
            else:
                return int(expr)

        except ValueError:
            if expr[0].isnumeric():
                message = (
                    f'{expr} is neither a variable '
                    'name nor a numeric literal'
                )
                raise ValueError(message)
            return expr

    def __str__(self):
        return f'{self.left}{self.op}{self.right}'

    def __repr__(self):
        return f'Expression({self.__str__()!r})'

    def __eq__(self, other):
        if not isinstance(other, Expression):
            return False
        return self.left == other.left and self.op == other.op and self.right == other.right

    def __contains__(self, item):
        return (item == self
                or isinstance(self.left, Expression) and item in self.left
                or item == self.left
                or isinstance(self.right, Expression) and item in self.right
                or item == self.right)


def _find_op_left(text: str, op: str) -> Optional[int]:
    brackets = 0
    for i, c in enumerate(text):
        if c == op and brackets == 0:
            return i
        elif c == '(':
            brackets += 1
        elif c == ')':
            brackets -= 1
    return None


def _find_op_right(text: str, op: str) -> Optional[int]:
    brackets = 0
    for i, c in list(enumerate(text))[::-1]:
        if c == op and brackets == 0:
            return i
        elif c == '(':
            brackets += 1
        elif c == ')':
            brackets -= 1
    return None


def _remove_brackets(text: str) -> str:
    while text[0] == '(' and _find_op_left(text[1:], ')') == len(text) - 2:
        text = text[1:-1]
    return text


def _split(text: str) -> tuple[str, str, str]:
    text = _remove_brackets(text.strip())
    for op in '+-*/':
        index = _find_op_right(text, op)
        if index is not None:
            return text[:index], text[index], text[index+1:]


if __name__ == '__main__':
    a = Expression('(a-b/a*b/c)+c*b')
    print(a)
