# Technical Sound Design Unity Demo Project

## Introduction
Hi!
Welcome to my Technical Sound Design Demo Project. The purpose of this project is to showcase some techniques and systems that I've used to implement audio and making it even more immersive. I'll be mainly focusing on 3 different types of sound phenomenons which are; Acoustics and realtime reflections, ambiences and explosions. 

Feel free to download the project and play around with it. Or you can watch the video below where I'm explaining the different implementations.

## Acoustics & Realtime Reflections

For the realtime reflections I’m using Audiokinetics Wwise and their reflect plugin. This is a geometry informed plugin which simulates realtime early reflections. I've added a couple of helper tools to speed up the workflow slightly. I’ve for example, created a one click solution to create reflective surfaces in the scene. Wwise requires all objects to have a SurfaceReflector component on them as well as a MeshCollider. (In newer versions of wwise you don't have to do this anymore.) The problem with this is that you might have a very complex object with a lot of mesh triangles, which will make the reflections bounce around sporadically. So my script simply estimates the shape of the mesh and creates a sub collider as a child of that object, which has far less triangles. Most of the geometry that I'm using is already very simple, but I've noticed that Wwise sometimes gets confused with ProBuilder's generated meshes.

<p align="center"><img src="Screenshots/SurfaceReflectorComponent.png" width="75%"></p>

## Ambiences

I wanted to approach the ambience design from a more simplistic perspective. Honestly, it wasn’t anything that I was planning on including in the presentation; but it was just a happy accident that it sounded pretty good and it was an interesting approach to the system design. You can see the full presentation of the ambience system from 2:54 in the video. One addition that I’m talking about in the video is the procedural wind simulation. I’ve spent a lot of time researching procedural audio and ways that it can be applied in games. If you’d like to read my dissertation (BSc) on procedural audio; You can find a link to it here.

Without going into too much detail, I think the place for procedural audio as it is today, is a combination of sample based audio and procedural models. What I mean by this is that certain elements of a sound can be physically modelled; such as the wind in my example, while it is feeding a parameter which controls a dynamic sample based implementation. So procedurally you could define the wind speed and model the whistle, gust and howl elements, while at the same time feeding a sample based model in your middleware, such as wwise in my case. This would utilize the quality of a sample based domain, but with the added flexibility of a procedural model. You could of course take this even further as well where you affect objects in the scene, such as swaying trees which are based on the wind speed and intensity.

## Explosions

For the explosions I’ve yet again approached a more linear interpretation when it comes to the sound design with some added flexibility to the implementation. As mentioned in the video, I’ve divided the sounds up into close, mid and far explosions where I’m also applying various distance attenuation and filtering to the elements. What I’ve focused on is the way an explosion works in real-life and applied a simplified model to that. I’ve designed the sounds to follow a typical overpressure curve over time. (Figure 3)

<p align="center"><img src="Screenshots/OverpressureOverTime.png" width="75%"></p>

This curve illustrates the way an explosion is a quick release of energy which forms a wavefront that is faster than the speed of sound. This sudden inrush of pressure creates an overpressure which moves outward from the blast epicenter. As a result of the positive pressure created, this will then be followed by a negative pressure to compensate. This is what we call the blastwave, and it is usually the negative pressure that results in a larger devastation. 
