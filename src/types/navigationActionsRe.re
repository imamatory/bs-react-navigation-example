open Utils;
module Types = ReactNavigationTypes;

type navigateParams('a, 'b) = {
  .
  "routeName": string,
  "action": Js.Undefined.t(Types.navAction('a)),
  "params": {. "route": Route.t}
};

type replaceParams('a, 'b) = {
  .
  "key": string,
  "routeName": string,
  "action": Js.Undefined.t(Types.navAction('a)),
  "params": {. "route": Route.t},
  "immediate": Js.boolean
};

type resetParams('a) = {
  .
  "index": int,
  "actions": array(Types.navAction('a)),
  "key": Js.Nullable.t(string)
};

type backParams('a) = {. "key": Js.Undefined.t(string)};

type resetKey = [ | `Navigator(string) | `RootNavigator];

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external _navigate : navigateParams('a, 'b) => Types.navAction('c) =
  "navigate";

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external _reset : resetParams('a) => Types.navAction('a) = "reset";

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external _replace : replaceParams('a, 'b) => Types.navAction('a) = "replace";

[@bs.module "react-navigation"] [@bs.scope "NavigationActions"]
external _back : backParams('a) => Types.navAction('a) = "back";

[@bs.send] external dispatch : (Types.Nav.t, Types.navAction('a)) => unit = "";

let navigate = (~action: option(Types.navAction('b))=?, route: Route.t, screen) =>
  _navigate({
    "routeName": screen,
    "params": {
      "route": route
    },
    "action": Js.Undefined.fromOption(action)
  });

let reset =
    (
      ~index: int=0,
      ~key: option(resetKey)=?,
      actions: array(Types.navAction('b))
    ) => {
  let key =
    Option.(
      key
      |> map(x =>
           switch x {
           | `Navigator(v) => Js.Nullable.return(v)
           | `RootNavigator => Js.Nullable.null
           }
         )
      |> default(Js.Nullable.undefined)
    );
  _reset({"index": index, "actions": actions, "key": key});
};

let replace =
    (~action: option(Types.navAction('b))=?, route: Route.t, key, screen) =>
  _replace({
    "key": key,
    "routeName": screen,
    "params": {
      "route": route
    },
    "action": Js.Undefined.fromOption(action),
    "immediate": Js.true_
  });

let back = (~key: option(string)=?, ()) =>
  _back({"key": Js.Undefined.fromOption(key)});
