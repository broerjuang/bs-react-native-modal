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
type swipeDirection = [ | `down | `left | `right | `up];

type orientation = [
  | `portrait
  | `portraitUpsideDown
  | `landscape
  | `landscapeLeft
  | `landscapeRight
];

let make:
  (
    ~animationIn: animation=?,
    ~animationOut: animation=?,
    ~animationInTiming: int=?,
    ~animationOutTiming: int=?,
    ~avoidKeyboard: bool=?,
    ~backdropColor: string=?,
    ~backdropOpacity: float=?,
    ~backdropTransitionInTiming: int=?,
    ~backdropTransitionOutTiming: int=?,
    ~isVisible: bool,
    ~onBackButtonPress: unit => unit=?,
    ~onBackdropPress: unit => unit=?,
    ~onModalHide: unit => unit=?,
    ~onModalShow: unit => unit=?,
    ~onSwipe: unit => unit=?,
    ~scrollOffset: int=?,
    ~scrollOffsetMax: int=?,
    ~scrollTo: unit => unit=?,
    ~swipeThreshold: int=?,
    ~swipeDirection: swipeDirection=?,
    ~useNativeDriver: bool=?,
    ~hideModalContentWhileAnimating: bool=?,
    ~supportedOrientations: array(orientation)=?,
    ~style: BsReactNative.Style.t=?,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );