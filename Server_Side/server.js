const express = require('express')
const app = express()
const port = process.env.PORT || 3000
const { db } = require('./firebase.js')

app.use(express.json())

app.get('/fetchData', async (req, res) => {
    try {
        const MACAddress = req.query.MACAddress
        const footFall = await db.collection('FootFallCollection').where('MACAddress', '==', MACAddress).orderBy('Time', 'asc').get()
        const data = footFall.docs.map(doc => doc.data())
        res.status(200).json({
            message: 'Data fetched successfully',
            data,
        })
    } catch (error) {
        console.log(error)
        res.sendStatus(500).json({message: error})
    }
})

app.get('/postData', async (req, res) => {
    try {
        const dateObj = new Date(Date.now())
        const Time = dateObj.toUTCString()
        const MACAddress = req.query.MACAddress
        const data = {
            MACAddress,
            Time
        }
        const result = await db.collection('FootFallCollection')
        const doc = await result.add(data)
        res.status(200).json({
            message: 'Data posted successfully',
            id: doc.id
        })
    } catch (error) {
        console.log(error)
        res.sendStatus(500).json({message: error})
    }
});

app.get('/', (req, res) => {
    res.send('Server is online')
})

app.listen(port, () => {
    console.log('Server has started on port: ' + port)
})