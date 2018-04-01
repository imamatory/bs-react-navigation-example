module StackNavigator = StackNavigatorRe;

module DrawerNavigator = DrawerNavigatorRe;

module NavigationActions = NavigationActionsRe;

module SafeAreaView = SafeAreaViewRe;

module Types = ReactNavigationTypes;

[@bs.send]
external _navigate :
  (Types.Nav.t, string, Types.navParams('a), Types.navAction('b)) => unit =
  "navigate";

let navigate =
    (
      navigation,
      ~params as p: option(Types.navParams('a))=?,
      ~action as a: option(Types.navAction('b))=?,
      route: Types.route
    ) => {
  let params =
    switch p {
    | Some(x) => x
    | None => Js.Obj.empty()
    };
  let action =
    switch a {
    | Some(x) => x
    | None => Js.Obj.empty()
    };
  _navigate(
    navigation,
    Types.Screen.(route |> tToJs),
    params,
    action
  );
};

let makeForceInset = SafeAreaView.makeForceInset;
