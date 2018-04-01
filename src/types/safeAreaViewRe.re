open Utils;

type forceInsetValue = [ | `Always | `Never];

type forceInset('a) = Js.t('a);

let makeForceInset =
    (
      ~top: option(forceInsetValue)=?,
      ~bottom: option(forceInsetValue)=?,
      ~left: option(forceInsetValue)=?,
      ~right: option(forceInsetValue)=?,
      ~vertical: option(forceInsetValue)=?,
      ~horizontal: option(forceInsetValue)=?,
      ()
    )
    : forceInset('a) => {
  let valToJs = x =>
    x
    |> Option.map(v =>
         switch v {
         | `Always => "always"
         | `Never => "never"
         }
       )
    |> Js.Null.fromOption;
  {
    "top": valToJs(top),
    "bottom": valToJs(bottom),
    "left": valToJs(left),
    "right": valToJs(right),
    "vertical": valToJs(vertical),
    "horizontal": valToJs(horizontal)
  };
};

[@bs.module "react-navigation"]
external safeAreaView : ReasonReact.reactClass = "SafeAreaView";

let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      ~isLandscape: option(bool)=?,
      ~forceInset: option(forceInset('a))=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=safeAreaView,
    ~props={
      "style": Js.Null.fromOption(style),
      "isLandscape": optToJsBool(isLandscape),
      "forceInset": Js.Null.fromOption(forceInset)
    },
    children
  );
