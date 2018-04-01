module Types = ReactNavigationTypes;

module Config = {
  type t;
  [@bs.obj]
  external make :
    (
      ~initialRouteName: string=?,
      ~headerMode: [@bs.string] [ | `float | `screen | `none]=?,
      ~navigationOptions: Types.navigationOptions('a)=?,
      unit
    ) =>
    t =
    "";
};

[@bs.module "react-navigation"]
external _stackNavigator :
  (Types.routeConfig('a), Config.t) => ReasonReact.reactClass =
  "StackNavigator";

let createRouteConfigParams = Types.createRouteConfigParams;

let make = (raw: Types.rawRouteConfig('a)) =>
  raw |> Types.convertRawRouteConfig |> _stackNavigator;
