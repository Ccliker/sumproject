const exp = require('express');

const app = exp();

app.listen('3300',console.log('http://localhost:3300'));
app.use(exp.urlencoded({extended:true}))
app.use(exp.json())
app.set('view engine','ejs');
app.get('/',(req,res)=>{
    res.send(req.body);
})
app.post('/setMessage',(req,res)=>{
    const data = req.body;
    console.log(data);
    res.render('index',{data:data})
})