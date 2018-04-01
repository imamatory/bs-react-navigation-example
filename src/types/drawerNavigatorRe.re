module Types = ReactNavigationTypes;

module Config = {
  type t;
  [@bs.obj]
  external make :
    (
      ~initialRouteName: string=?,
      ~contentComponent: ReasonReact.reactClass=?,
      ~drawerPosition: [@bs.string] [ | `left | `right]=?,
      unit
    ) =>
    t =
    "";
};

[@bs.module "react-navigation"]
external _drawerNavigator :
  (Types.routeConfig('a), Config.t) => ReasonReact.reactClass =
  "DrawerNavigator";

let createRouteConfigParams = Types.createRouteConfigParams;

let make = (raw: Types.rawRouteConfig('a)) =>
  raw |> Types.convertRawRouteConfig |> _drawerNavigator;
