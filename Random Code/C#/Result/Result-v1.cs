public class Result<T, E>
    where T : class
    where E : class
{
    public enum ResultType
    {
        Ok,
        Error
    }

    public T Value { get; private set; }
    public E Error { get; private set; }

    public ResultType Type { get; private set; }

    public Result(Ok<T> ok)
    {
        Value = ok.Value;
        Type = ResultType.Ok;
    }

    public Result(Error<E> error)
    {
        Error = error.Value;
        Type = ResultType.Error;
    }

    public bool IsOk => Type == ResultType.Ok;
    public bool IsError => Type == ResultType.Error;

    public bool IsOkAnd(Func<T, bool> predicate) => IsOk && predicate(Value);
    public bool IsErrorAnd(Func<E, bool> predicate) => IsError && predicate(Error);

    public T GetOk() => IsOk ? Value : null;
    public E GetError() => IsError ? Error : null;

    public T Expect(string message) => IsOk ? Value : throw new Exception(message);
    public E ExpectError(string message) => IsError ? Error : throw new Exception(message);

    public T Unwrap() => IsOk ? Value : throw new Exception($"Unwrap called on Error: {Error}");
    public E UnwrapError() => IsError ? Error : throw new Exception($"UnwrapError called on Ok: {Value}");

    public T UnwrapOr(T defaultValue) => IsOk ? Value : defaultValue;

    public static implicit operator bool(Result<T, E> result) => result.IsOk;
}

public class Ok<T>
    where T : class
{
    public T Value { get; private set; }

    public Ok(T value) {
        Value = value;
    }
}

public class Error<E>
    where E : class
{
    public E Value { get; private set; }

    public Error(E value)
    {
        Value = value;
    }
}

class Program {
    public static void Main(string[] args) {
        var result = new Result<string, string>(new Ok<string>("Hello World"));
        Console.WriteLine(result.IsOk);
        Console.WriteLine(result.IsError);
        Console.WriteLine(result.IsOkAnd(x => x == "Hello World"));
        Console.WriteLine(result.IsErrorAnd(x => x == "Hello World"));
    }
}

Program.Main(null);