const express = require('express')
const { FieldValue } = require('firebase-admin/firestore')
const app = express()
const port = 3000
const { db } = require('./firebase.js')
const { count } = require('firebase/firestore')

app.use(express.json())


app.get('/fetchData', async (req, res) => {
    try {
        const MACAddress = req.query.MACAddress;
        console.log('fetching data');
        const footFall = await db.collection('FootFallCollection').where('MACAddress', '==', MACAddress).get()
        // console.log('footFall' , footFall);
        const data = footFall.docs.map(doc => doc.data());
        // const doc = await footFall.get()
        
        // if (!doc.exists) {
        //     return res.sendStatus(400).send('No data found')
        // }
        res.status(200).send({
            message: 'Data fetched successfully',
            data,
        })
        
    } catch (error) {
        console.log(error);
        res.sendStatus(500)
        res.send(error)
    }
})



app.get('/postData', async (req, res) => {
    try {
        const days = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
        console.log('posting data');
        const dateObj = new Date(Date.now());
        const Time = dateObj.toUTCString();
        const MACAddress = req.query.MACAddress;
        const data = {
            MACAddress,
            Time
        };
        // return res.send(data); 
        const result = await db.collection('FootFallCollection');
        const doc = await result.add(data);
        res.status(200).send({
            message: 'Data posted successfully',
            id: doc.id
        });
    } catch (error) {
        console.log(error);
        res.sendStatus(500);
        res.send(error);
    }
});


app.get('/' , (req, res) => {
    res.send('Hello World')
})
app.listen(port, () => console.log(`Server has started on port: ${port}`))