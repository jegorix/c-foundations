#
# all_ops = {
#     # '+': add,
#     # '-': sub,
#     # '*': mul,
#     # '/': div,
#     # '^': power,
#
# }
#
# def binary_op(token):
#     def make_binop(func):
#         def redef(stack):
#             if len(stack) < 2:
#                 raise Exception(f'Not enough operands(now = {len(stack)})')
#             b = stack.pop()
#             a = stack.pop()
#             result = func(a, b)
#             stack.append(result)
#
#             return result
#         all_ops[token] = redef
#         return redef
#     return make_binop
#
#
# # add = binary_op('+')('add')
# @binary_op('+')
# def add(a, b):
#     return a + b
#
# @binary_op('-')
# def sub(a, b):
#     return a - b
#
# @binary_op('*')
# def mul(a,b):
#     return a * b
#
# @binary_op('//')
# def div(a, b):
#     return a // b
#
# @binary_op('^')
# def power(a, b):
#     return a ** b
#
#
#
#
#
#
# def priority(op):
#     if op in ('+', '-'):
#         return 1
#     elif op in ('*', '/'):
#         return 2
#     elif op in '(':
#         return 0
#     return -1
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# def execute_program(program: str):
#     stack = []
#     for token in program.split():
#         operation = all_ops.get(token, None)
#         if operation is not None:
#             operation(stack)
#
#         else:
#             try:
#                 stack.append(int(token))
#             except ValueError:
#                 print(f"{token!r} is unknown symbol")
#
#     if len(stack) != 1:
#         raise("After calculation exists more than one number")
#
#     return stack.pop()
#
#
#
# print(execute_program('5 6 7 + -'))
#
#
#

def priority(op):
    if op == '+' or op == '-':
        return 1
    elif op == '*' or op == '/':
        return 2
    else:
        return 0


def convert_infix_to_rpn(expression):
    tokens = expression.split()
    stack = []
    result = []

    for token in tokens:
        if token.isdigit():
            result.append(token)

        elif token == '(':
            stack.append(token)

        elif token == ')':
            while stack and stack[-1] != '(':
                result.append(stack.pop())
            stack.pop()

        else:
            while stack and priority(stack[-1]) >= priority(token):
                result.append(stack.pop())
            stack.append(token)

    while stack:
        result.append(stack.pop())

    return ' '.join(result)



def rpn_calculator(expression):
    expression = convert_infix_to_rpn(expression)
    tokens = expression.split()
    stack = []

    for token in tokens:
        if token.isdigit():
            stack.append(int(token))

        elif token == '+':
            b = stack.pop()
            a = stack.pop()
            result = a + b
            stack.append(result)

        elif token == '-':
            b = stack.pop()
            a = stack.pop()
            result = a - b
            stack.append(result)

        elif token == '*':
            b = stack.pop()
            a = stack.pop()
            result = a * b
            stack.append(result)

        elif token == '/':
            b = stack.pop()
            a = stack.pop()
            result = a // b
            stack.append(result)


    if len(stack) != 1:
        raise Exception('Invalid expression')

    return stack[-1]


example = "( 7 - 3 ) * ( 8 + 2 ) / 5"

print(example)
print(convert_infix_to_rpn(example))
print(rpn_calculator(example))



