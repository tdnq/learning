'use strict';

const e = React.createElement;

class LikeButton extends React.Component {
  constructor(props) {
    super(props);
    this.state = { liked: false };
  }

  render() {
    if (this.state.liked) {
      return 'You liked this.';
    }

    return e(
      'button',
      { onClick: () => this.setState({ liked: true }) },
      'Like'
    );
  }
}
function Hello() {
  return /*#__PURE__*/React.createElement("div", null, "hello ,word;");
}



const domContainer = document.querySelector('#root');
ReactDOM.render(e(Hello), domContainer);