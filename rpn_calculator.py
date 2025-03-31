
def binary_op(func):
    def redef(stack):
        if len(stack) < 2:
            raise Exception(f'Not enough operands(now = {len(stack)})')
        b = stack.pop()
        a = stack.pop()
        result = func(a, b)
        stack.append(result)
        return result
    return redef

@binary_op
def add(a, b):
    return a + b

@binary_op
def sub(a, b):
    return a - b




def execute_program(program: str):
    stack = []
    for token in program.split():
        if token == '+':


            add(stack)

        elif token == '-':
            if len(stack) < 2:
                raise Exception(f'Not enough operands(now = {len(stack)})')

            sub(stack)

        else:
            try:
                stack.append(int(token))
            except ValueError:
                print(f"{token!r} is unknown symbol")

    if len(stack) != 1:
        raise("After calculation exists more than one number")

    return stack.pop()



print(execute_program('5 6 7 + -'))



