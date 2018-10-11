/* Infix operator to work with nullable default value */
let (<$>) = Belt.Option.map;

[@bs.deriving jsConverter]
type animation = [
  | `slideInUp
  | `slideInDown
  | `slideInRight
  | `slideInLeft
  | `slideOutDown
  | `slideOutUp
  | `slideOutDown
  | `slideOutRight
  | `slideOutLeft
];

[@bs.deriving jsConverter]
type swipeDirection = [ | `up | `down | `left | `right];

[@bs.deriving jsConverter]
type orientation = [
  | `portrait
  | [@bs.as "portrait-upside-down"] `portraitUpsideDown
  | `landscape
  | [@bs.as "landscape-left"] `landscapeLeft
  | [@bs.as "landscape-right"] `landscapeRight
];

[@bs.module "react-native-modal"]
external _reactNativeModal: ReasonReact.reactClass = "default";

let make =
    (
      ~animationIn: option(animation)=?,
      ~animationOut: option(animation)=?,
      ~animationInTiming: option(int)=?,
      ~animationOutTiming: option(int)=?,
      ~avoidKeyboard: option(bool)=?,
      ~backdropColor: option(string)=?,
      ~backdropOpacity: option(float)=?,
      ~backdropTransitionInTiming: option(int)=?,
      ~backdropTransitionOutTiming: option(int)=?,
      ~isVisible: bool,
      ~onBackButtonPress: option(unit => unit)=?,
      ~onBackdropPress: option(unit => unit)=?,
      ~onModalHide: option(unit => unit)=?,
      ~onModalShow: option(unit => unit)=?,
      ~onSwipe: option(unit => unit)=?,
      ~scrollOffset: option(int)=?,
      ~scrollOffsetMax: option(int)=?,
      ~scrollTo: option(unit => unit)=?,
      ~swipeThreshold: option(int)=?,
      ~swipeDirection: option(swipeDirection)=?,
      ~useNativeDriver: option(bool)=?,
      ~hideModalContentWhileAnimating: option(bool)=?,
      ~supportedOrientations: option(array(orientation))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=_reactNativeModal,
    ~props=
      Js.Nullable.{
        "isVisible": isVisible,
        "animationIn": fromOption(animationIn <$> animationToJs),
        "animationInTiming": fromOption(animationInTiming),
        "animationOut": fromOption(animationOut <$> animationToJs),
        "animationOutTiming": fromOption(animationOutTiming),
        "avoidKeyboard": fromOption(avoidKeyboard),
        "backdropColor": fromOption(backdropColor),
        "backdropOpacity": fromOption(backdropOpacity),
        "backdropTransitionInTiming": fromOption(backdropTransitionInTiming),
        "backdropTransitionOutTiming":
          fromOption(backdropTransitionOutTiming),
        "onBackButtonPress": fromOption(onBackButtonPress),
        "onBackdropPress": fromOption(onBackdropPress),
        "onModalHide": fromOption(onModalHide),
        "onModalShow": fromOption(onModalShow),
        "onSwipe": fromOption(onSwipe),
        "scrollOffset": fromOption(scrollOffset),
        "scrollOffsetMax": fromOption(scrollOffsetMax),
        "scrollTo": fromOption(scrollTo),
        "swipeThreshold": fromOption(swipeThreshold),
        "swipeDirection": fromOption(swipeDirection <$> swipeDirectionToJs),
        "useNativeDriver": fromOption(useNativeDriver),
        "supportedOrientations":
          fromOption(supportedOrientations <$> Array.map(orientationToJs)),
        "hideModalContentWhileAnimating":
          fromOption(hideModalContentWhileAnimating),
        "style": fromOption(style),
      },
    children,
  );