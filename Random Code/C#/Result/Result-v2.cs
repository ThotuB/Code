abstract class Result<T, E>
    where T : class
    where E : class
{
    public enum ResultType {
        Ok,
        Error
    }
    
    public ResultType Type { get; private set; }
    public bool IsOk { get; private set; }
    public bool IsError { get; private set; }

    protected Result(ResultType type) {
        Type = type;
        IsOk = type == ResultType.Ok;
        IsError = type == ResultType.Error;
    }

    public abstract bool IsOkAnd(Func<T, bool> predicate);
    public abstract bool IsErrorAnd(Func<E, bool> predicate);
    public abstract T GetOk();
    public abstract E GetError();
    public abstract T Expect(string message);
    public abstract E ExpectError(string message);
    public abstract T Unwrap();
    public abstract E UnwrapError();
    public abstract T UnwrapOr(T defaultValue);

    protected abstract bool OpTrue();
    protected abstract bool OpFalse();

    public static bool operator true(Result<T, E> result) {
        return result.OpTrue();
    }
    public static bool operator false(Result<T, E> result) {
        return result.OpFalse();
    }

    public abstract override string ToString();
}

class Ok<T, E> : Result<T, E>
    where T : class
    where E : class
{
    public T Value { get; private set; }

    public Ok(T value) : base(ResultType.Ok)
    {
        Value = value;
    }

    public override bool IsOkAnd(Func<T, bool> predicate) => predicate(Value);
    public override bool IsErrorAnd(Func<E, bool> predicate) => false;
    public override T GetOk() => Value;
    public override E GetError() => null;
    public override T Expect(string message) => Value;
    public override E ExpectError(string message) { throw new Exception(message); }
    public override T Unwrap() => Value;
    public override E UnwrapError() { throw new Exception("UnwrapError on an Ok value: " + Value); }
    public override T UnwrapOr(T defaultValue) => Value;

    protected override bool OpTrue() => true;
    protected override bool OpFalse() => false;

    public override string ToString() => $"Ok({Value})";
}

class Error<T, E> : Result<T, E>
    where T : class
    where E : class
{
    public E Value { get; private set; }

    public Error(E value) : base(ResultType.Error)
    {
        Value = value;
    }

    public override bool IsOkAnd(Func<T, bool> predicate) => false;
    public override bool IsErrorAnd(Func<E, bool> predicate) => predicate(Value);
    public override T GetOk() => null;
    public override E GetError() => Value;
    public override T Expect(string message) { throw new Exception(message); }
    public override E ExpectError(string message) => Value;
    public override T Unwrap() { throw new Exception("Unwrap on an Error value: " + Value); }
    public override E UnwrapError() => Value;
    public override T UnwrapOr(T defaultValue) => defaultValue;

    protected override bool OpTrue() => false;
    protected override bool OpFalse() => true;

    public override string ToString() => $"Error({Value})";
}

class Program {
    public static Result<string, string> Divide(int x, int y) {
        if (y == 0) {
            return new Error<string, string>("Division by zero");
        }
        return new Ok<string, string>($"{x} / {y} = {x / y}");
    }

    public static void Main() {
        var result = Divide(42, 0);
        Console.WriteLine(result);
        Console.WriteLine(result.IsOk);
        Console.WriteLine(result.IsError);
        Console.WriteLine(result.IsOkAnd(x => x.Length > 0));
        Console.WriteLine(result.IsErrorAnd(x => x.Length > 0));
    }
}

Program.Main()