# bs-react-native-modal

this is a binding of [react-native-modal](https://github.com/react-native-community/react-native-modal)

## Usage

see the [rei](https://github.com/broerjuang/bs-react-native-modal/blob/master/src/ReactNativeModal.rei) for detail documentation

```ocaml
module ModalTester = {
  open BsReactNative;
  type state = {isModalVisible: bool};
  type action =
    | ToggleModal;

  let component = ReasonReact.reducerComponent("ModalTester");
  let make = _children => {
    ...component,
    initialState: () => {isModalVisible: false},
    reducer: (action, state) =>
      switch (action) {
      | ToggleModal =>
        ReasonReact.Update({isModalVisible: !state.isModalVisible})
      },
    render: self =>
      <View>
        <TouchableOpacity onPress={() => self.send(ToggleModal)}>
          <Text value="Show Modal" />
        </TouchableOpacity>
        <ReactNativeModal isVisible={self.state.isModalVisible}>
          <View>
            <Text value="Hello!" />
            <TouchableOpacity onPress={() => self.send(ToggleModal)}>
              <Text value="Hide Me" />
            </TouchableOpacity>
          </View>
        </ReactNativeModal>
      </View>,
  };
};
```

## Installation

Use yarn or npm

```shell
$ yarn add bs-react-native-modal
```

Then update your bsconfig.json

```json
{
  "bs-dependencies": ["bs-react-native-modal"]
}
```
