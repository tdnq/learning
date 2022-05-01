import logo from './logo.svg';
import './App.css';
import React from 'react';
import SetStateExe from './components/SetStateExe';
function App() {
  let [arr, setArr] = React.useState([
    {
      id: 1,
      name: 'td',
      color: 'red'
    },
    {
      id: 2,
      name: 'li',
      color: 'blue'
    }
  ]);
  const change = function (item) {
    console.log('fa'); //react是合成事件
  }
  // key 是为了标识组件是重建还是复用,最好用业务数据标识key,如果用index作key可能会导致操作与vdom执行不一致.
  return (
    <div className="App">
      <ul>
        {
          arr.map((item, index) => {
            return <div key={item.id}>
              <li style={{ color: item.color }} >{item.name}</li>
              <input onChange={change} type="checkbox" />
            </div>
          })
        }
      </ul>
      <button onClick={() => {
        let temp = arr.slice(0);
        temp.reverse();
        setArr(temp)
      }}>reverse</button>
      <SetStateExe />
    </div>
  );
}

export default App;
