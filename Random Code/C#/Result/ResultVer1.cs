// create rust-like std::result::Result in C#

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Result<T, E>
{
    public enum ResultType
    {
        Ok,
        Error
    }

    public T Value { get; private set; }
    public E Error { get; private set; }

    public ResultType Type { get; private set; }

    public static Result FromOk(T value)
    {
        Value = value;
        Type = ResultType.Ok;
    }

    public Result(E error)
    {
        Error = error;
        Type = ResultType.Error;
    }

    public bool IsOk => Type == ResultType.Ok;

    public bool IsError => Type == ResultType.Error;

    public bool IsOkAnd(Func<T, bool> predicate) => IsOk && predicate(Value);

    public bool IsErrorAnd(Func<E, bool> predicate) => IsError && predicate(Error);
}

public class Ok<T>
{
    public T Value { get; private set; }

    public Ok(T value)
    {
        Value = value;
    }
}

public class Error<E>
{
    public E Value { get; private set; }

    public Error(E value)
    {
        Value = value;
    }
}

class Program {
    public static void Main(string[] args) {
        var result = new Result<string, string>("Hello World");
        Console.WriteLine(result.IsOk);
        Console.WriteLine(result.IsError);
        Console.WriteLine(result.Ok().Value);
        Console.WriteLine(result.Error().Value);
        Console.WriteLine(result.IsOkAnd(x => x == "Hello World"));
        Console.WriteLine(result.IsErrorAnd(x => x == "Hello World"));
        Console.WriteLine(result.IsOkAnd(x => x == "Hello World!"));
        Console.WriteLine(result.IsErrorAnd(x => x == "Hello World!"));
    }
}

Program.Main(null);