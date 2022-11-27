import React from "react";
export default class Com extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            count: 0,
        }
    }
    componentDidMount() {
        this.setState({ count: this.state.count + 1 });
        console.log(this.state.count, '--1');
        this.setState({ count: this.state.count + 1 });
        console.log(this.state.count, '--2');
        setTimeout(() => {
            this.setState({ count: this.state.count + 1 });
            console.log(this.state.count, '--3');
        }, 0);
        setTimeout(() => {
            this.setState({ count: this.state.count + 1 });
            console.log(this.state.count, '--4');
        }, 0);
    }
    render() {
        return <div>
            setstate com
        </div>
    }
}