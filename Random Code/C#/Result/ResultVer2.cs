interface IResult<T, E> 
{
    bool IsOk();
    bool IsError();
    bool IsOkAnd(Func<T, bool> predicate);
    bool IsErrorAnd(Func<E, bool> predicate);
}

class Result<T, E>
{
    public enum ResultType
    {
        Ok,
        Error
    }
    
    public ResultType Type { get; private set; }

    public Result(ResultType type)
    {
        Type = type;
    }
}

class Ok<T> : Result<T, E>
{
    public T Value { get; private set; }

    public Ok(T value) : base(ResultType.Ok)
    {
        Value = value;
    }

    public override bool IsOk() => true;
    public override bool IsError() => false;
    public override bool IsOkAnd(Func<T, bool> predicate) => predicate(Value);
    public override bool IsErrorAnd(Func<string, bool> predicate) => false;
}

class Error<E> : Result<string, E>
{
    public E Value { get; private set; }

    public Error(E value) : base(ResultType.Error)
    {
        Value = value;
    }

    public override bool IsOk() => false;
    public override bool IsError() => true;
    public override bool IsOkAnd(Func<string, bool> predicate) => false;
    public override bool IsErrorAnd(Func<E, bool> predicate) => predicate(Value);
}

class Program {
    public static void Main() {
        Result<T, E> result = new Ok<string>("Hello World");
        Console.WriteLine(result.IsOk());
        Console.WriteLine(result.IsError());
        Console.WriteLine(result.IsOkAnd(x => x == "Hello World"));
        Console.WriteLine(result.IsErrorAnd(x => x == "Hello World"));
    }
}

Program.Main()