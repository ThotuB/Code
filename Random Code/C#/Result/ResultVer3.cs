class Result<T, E> {
    public enum ResultType {
        Ok,
        Error
    }
    
    public ResultType Type { get; private set; }
    
    public static void Ok(T value) {
        return new Ok<T>(value);
    }
}