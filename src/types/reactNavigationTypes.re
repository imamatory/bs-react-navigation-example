module Nav = {
  type t;
  [@bs.send] external getParam : (t, string) => 'a = "";
  let route = nav : Route.t => getParam(nav, "route");
};

module Screen = {
  [@bs.deriving jsConverter]
  type t = [ | `Index | `Home];
  let fromRoute =
    fun
    | (`Index | `Home) as r => r
};

type route = Route.t;

type navParams('a) = Js.t('a);

type navAction('a) = Js.t('a);

type routeConfig('a) = Js.Dict.t('a);

type routeConfigParams('a) = Js.t('a);

type rawRouteConfig('a) = array((Screen.t, routeConfigParams('a)));

type navigationOptions('a) = Js.t('a);

let convertRawRouteConfig = (raw: rawRouteConfig('a)) : routeConfig('b) =>
  Js.Dict.fromArray(Js.Array.map(((r, c)) => (Screen.tToJs(r), c), raw));

let createRouteConfigParams =
    (screen: ReasonReact.reactClass)
    : routeConfigParams('a) => {
  "screen": screen
};
