import React from "react";
export default class Com extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            name: 'li s',
            age: 12,
        }
        let self = this;
        this.fn = {
            changeName: {
                fn: () => {
                    this.setState((val) => { debugger; return { name: val.name + '1' } }); //class中 箭头函数的this总是指向class
                }
            },
            changeName2: function () {
                self.setState((val) => { debugger; return { name: val.name + '2' } });
            }
        }
    }
    render() {
        console.log(this.state, 'state');
        return <h1 onClick={() => { this.fn.changeName.fn(); this.fn.changeName2() }}>{this.state.name}</h1>
    }
}