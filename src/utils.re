let optToJsBool = (a: option(bool)) : Js.nullable(Js.boolean) =>
  Js.Nullable.from_opt(Js.Option.map([@bs] ((x) => Js.Boolean.to_js_boolean(x)), a));

module Option {
  type t('a) = option('a);
  let map = (f: 'a => 'b, v: t('a)) : t('b) =>
    switch v {
    | None => None
    | Some(x) => Some(f(x))
    };
  let default = (d: 'a, v: t('a)) : 'a =>
    switch v {
    | None => d
    | Some(v) => v
    };
}
